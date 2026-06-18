#!/usr/bin/env python3
"""
Fetches LeetCode stats for Ashwin_Dev_27 via the public GraphQL API
and updates the README.md between marker comments.

Markers in README.md:
  <!-- LEETCODE-STATS:START -->
  <!-- LEETCODE-STATS:END -->
"""

import re
import sys
import requests
from datetime import datetime, timezone

# ─── Config ──────────────────────────────────────────────────────────────────

USERNAME    = "Ashwin_Dev_27"
README_PATH = "README.md"
GQL_URL     = "https://leetcode.com/graphql"
HEADERS     = {
    "Content-Type": "application/json",
    "Referer":      "https://leetcode.com",
    "Origin":       "https://leetcode.com",
    "User-Agent":   "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36",
}

QUERY = """
query getUserStats($username: String!) {
  matchedUser(username: $username) {
    profile {
      ranking
    }
    submitStats: submitStatsGlobal {
      acSubmissionNum {
        difficulty
        count
      }
    }
  }
  allQuestionsCount {
    difficulty
    count
  }
}
"""

# ─── Fetch ────────────────────────────────────────────────────────────────────

def fetch_stats():
    try:
        resp = requests.post(
            GQL_URL,
            json={"query": QUERY, "variables": {"username": USERNAME}},
            headers=HEADERS,
            timeout=15,
        )
        resp.raise_for_status()
        data = resp.json()
        if "errors" in data:
            print(f"[ERROR] GraphQL returned errors: {data['errors']}")
            return None
        return data["data"]
    except Exception as exc:
        print(f"[ERROR] Request failed: {exc}")
        return None

# ─── Build block ──────────────────────────────────────────────────────────────

def build_block(data):
    user     = data["matchedUser"]
    ranking  = user["profile"]["ranking"]

    solved = {s["difficulty"]: s["count"] for s in user["submitStats"]["acSubmissionNum"]}
    totals = {q["difficulty"]: q["count"] for q in data["allQuestionsCount"]}

    all_s    = solved.get("All",    0)
    easy_s   = solved.get("Easy",   0)
    med_s    = solved.get("Medium", 0)
    hard_s   = solved.get("Hard",   0)

    all_t    = totals.get("All",    1)  # avoid div-by-zero
    easy_t   = totals.get("Easy",   0)
    med_t    = totals.get("Medium", 0)
    hard_t   = totals.get("Hard",   0)

    pct  = round((all_s / all_t) * 100, 1)
    now  = datetime.now(timezone.utc).strftime("%d %b %Y · %H:%M UTC")

    # Progress bars (10 chars wide)
    def bar(solved, total, width=10):
        filled = round((solved / total) * width) if total else 0
        return "█" * filled + "░" * (width - filled)

    easy_bar = bar(easy_s, easy_t)
    med_bar  = bar(med_s,  med_t)
    hard_bar = bar(hard_s, hard_t)

    return f"""\
<!-- LEETCODE-STATS:START -->
## 🏆 LeetCode Progress

> 🔄 Auto-synced on every push &nbsp;|&nbsp; [View Profile ↗](https://leetcode.com/u/Ashwin_Dev_27/)

| Metric | Value |
|:---|:---|
| 🌐 **Global Rank** | #{ranking:,} |
| ✅ **Total Solved** | **{all_s}** / {all_t} &nbsp;`{pct}%` |
| 🟢 Easy | {easy_s} / {easy_t} &nbsp; `{easy_bar}` |
| 🟡 Medium | {med_s} / {med_t} &nbsp; `{med_bar}` |
| 🔴 Hard | {hard_s} / {hard_t} &nbsp; `{hard_bar}` |

<sub>🕐 Last synced: {now}</sub>
<!-- LEETCODE-STATS:END -->"""

# ─── Update README ────────────────────────────────────────────────────────────

def update_readme(block):
    with open(README_PATH, "r", encoding="utf-8") as f:
        content = f.read()

    pattern = r"<!-- LEETCODE-STATS:START -->.*?<!-- LEETCODE-STATS:END -->"
    if not re.search(pattern, content, re.DOTALL):
        print("[ERROR] Markers not found in README.md — add them first.")
        sys.exit(1)

    new_content = re.sub(pattern, block, content, flags=re.DOTALL)

    with open(README_PATH, "w", encoding="utf-8") as f:
        f.write(new_content)

    print("[OK] README.md updated successfully.")

# ─── Main ────────────────────────────────────────────────────────────────────

if __name__ == "__main__":
    print(f"[INFO] Fetching LeetCode stats for: {USERNAME}")
    data = fetch_stats()

    if not data:
        print("[WARN] Skipping update — keeping last known stats.")
        sys.exit(0)   # Exit 0 so the GitHub Action doesn't fail

    block = build_block(data)
    print("\n" + block + "\n")
    update_readme(block)
