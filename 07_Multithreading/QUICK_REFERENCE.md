# Multithreading Quick Reference

| Primitive | Header | Use |
|-----------|--------|-----|
| std::thread | <thread> | Run function concurrently |
| std::mutex | <mutex> | Mutual exclusion |
| std::lock_guard | <mutex> | RAII lock wrapper |
| std::unique_lock | <mutex> | Flexible locking |
| std::condition_variable | <condition_variable> | Signalling |
| std::atomic | <atomic> | Lock-free atomic ops |
| std::async | <future> | Launch task |
| std::future | <future> | Retrieve async result |
| std::promise | <future> | Set value asynchronously |

```cpp
std::mutex m; int x=0;
{
  std::lock_guard<std::mutex> lk(m);
  ++x;
}
```

