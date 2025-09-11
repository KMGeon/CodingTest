

```cpp
// Stack 기반 DFS (반복문 사용)
void DFS_stack(int start) {
    stack<int> s;
    s.push(start);
    
    while (!s.empty()) {
        int here = s.top();
        s.pop();
        
        if (visited[here]) continue;
        
        visited[here] = 1;
        cout << here << endl;
        
    }
}
```