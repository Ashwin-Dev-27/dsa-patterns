# 📚 Pattern 06 — Stack

## 🧠 Core Idea
A **stack** is a LIFO (Last In, First Out) data structure. In DSA, it's the go-to tool whenever you need to:
- Track the **most recent** element and compare it to the next
- Simulate a **"undo"** or **backtracking** behaviour
- Detect matching **pairs or brackets**
- Maintain a **monotonic** sequence (monotonic stack)

---

## 🔑 When to Use a Stack

| Signal in the problem | Pattern |
|-----------------------|---------|
| "adjacent duplicates" | Stack — push/pop pairs |
| "valid parentheses" / "balanced brackets" | Stack — match open/close |
| "next greater element" | Monotonic Stack |
| "daily temperatures" / "span" problems | Monotonic Stack |
| "undo / revert last action" | Stack |
| "evaluate expression" | Two stacks (operands + operators) |

---

## 📐 Templates

### 1 — Adjacent Duplicate Removal
```cpp
stack<char> st;
for (char c : s) {
    if (!st.empty() && st.top() == c)
        st.pop();           // remove the duplicate pair
    else
        st.push(c);
}
// drain stack → reverse for correct order
string result;
while (!st.empty()) { result += st.top(); st.pop(); }
reverse(result.begin(), result.end());
```

### 2 — Valid Parentheses
```cpp
stack<char> st;
for (char c : s) {
    if (c == '(' || c == '[' || c == '{') { st.push(c); continue; }
    if (st.empty()) return false;
    if (c == ')' && st.top() != '(') return false;
    if (c == ']' && st.top() != '[') return false;
    if (c == '}' && st.top() != '{') return false;
    st.pop();
}
return st.empty();
```

### 3 — Monotonic Stack (Next Greater Element)
```cpp
stack<int> st;   // stores indices
vector<int> res(n, -1);
for (int i = 0; i < n; i++) {
    while (!st.empty() && nums[st.top()] < nums[i]) {
        res[st.top()] = nums[i];
        st.pop();
    }
    st.push(i);
}
```

---

## ✅ Problems Logged

| LC #  | Problem | Difficulty | File | Approach |
|-------|---------|------------|------|----------|
| 1047  | Remove All Adjacent Duplicates In String | 🟢 Easy | [1047_RemoveDuplicates.cpp](./1047_RemoveDuplicates.cpp) | Push/pop pairs |
| 20    | Valid Parentheses | 🟢 Easy | [20_ValidParentheses.cpp](./20_ValidParentheses.cpp) | Stack match open/close |
| 496   | Next Greater Element I | 🟢 Easy | [496_NextGreaterElement.cpp](./496_NextGreaterElement.cpp) | Monotonic stack (right→left) + hash map |
| 739   | Daily Temperatures | 🟡 Medium | [739_DailyTemperatures.cpp](./739_DailyTemperatures.cpp) | Monotonic stack of indices (right→left) |
| 503   | Next Greater Element II | 🟡 Medium | [503_NextGreaterElementII.cpp](./503_NextGreaterElementII.cpp) | Monotonic stack + pre-loaded circular wrap |
| 1209  | Remove All Adjacent Duplicates in String II | 🟡 Medium | [1209_RemoveDuplicatesII.cpp](./1209_RemoveDuplicatesII.cpp) | Stack of (char, count) pairs |

---

## 🏃 How to Run

```bash
# Compile & run (from repo root)
g++ -std=c++17 -o out 06_Stack/1047_RemoveDuplicates.cpp && ./out
g++ -std=c++17 -o out 06_Stack/20_ValidParentheses.cpp && ./out
g++ -std=c++17 -o out 06_Stack/496_NextGreaterElement.cpp && ./out
g++ -std=c++17 -o out 06_Stack/739_DailyTemperatures.cpp && ./out
g++ -std=c++17 -o out 06_Stack/503_NextGreaterElementII.cpp && ./out

# Or via PowerShell helper
.\run.ps1 06_Stack/1047_RemoveDuplicates.cpp
.\run.ps1 06_Stack/20_ValidParentheses.cpp
.\run.ps1 06_Stack/496_NextGreaterElement.cpp
.\run.ps1 06_Stack/739_DailyTemperatures.cpp
.\run.ps1 06_Stack/503_NextGreaterElementII.cpp
.\run.ps1 06_Stack/1209_RemoveDuplicatesII.cpp
```

### Expected Output
```
[PASS] Test 1 | "abbaca" -> "ca"  (expected: "ca") | standard LC example: ab→abb→b→bca→ca
[PASS] Test 2 | "azxxzy" -> "ay"  (expected: "ay") | azxxzy → azzy → ay
[PASS] Test 3 | "aa" -> ""  (expected: "") | single pair, fully removed
[PASS] Test 4 | "abc" -> "abc"  (expected: "abc") | no duplicates, unchanged
[PASS] Test 5 | "a" -> "a"  (expected: "a") | single char
[PASS] Test 6 | "aabbcc" -> ""  (expected: "") | three pairs: aa+bb+cc → empty
[PASS] Test 7 | "abba" -> ""  (expected: "") | chain collapse: ab→abba→aa→empty
[PASS] Test 8 | "aabbbaa" -> "b"  (expected: "b") | aa removed, bb removed, b remains, aa removed → b

✅  All tests executed.
```
