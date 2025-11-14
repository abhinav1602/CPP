# File I/O Quick Reference

| Feature | Example | Notes |
|---------|---------|-------|
| ofstream | `ofstream out("f.txt");` | Write text |
| ifstream | `ifstream in("f.txt");` | Read text |
| fstream | read + write | Combined mode |
| binary write | `out.write((char*)p,n);` | Raw bytes |
| stringstream | parsing text | Format conversions |
| iomanip | `setw, setprecision` | Formatting |

Parse line:
```cpp
std::istringstream iss("42 text"); int i; std::string s; iss>>i>>s;
```

