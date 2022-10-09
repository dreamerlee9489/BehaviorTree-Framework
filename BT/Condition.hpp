#if !defined(CONDITION_HPP)
#define CONDITION_HPP

#include "./IBehavior.hpp"
#include <functional>

namespace BT {
class Condition : public IBehavior {
protected:
  void Enter() override {}

  EStatus Execute() override {
    if (m_pTask && m_pTask(m_pAgent))
      return EStatus::Success;
    return EStatus::Failure;
  }

  void Exit() override {}

public:
  typedef std::function<bool(IAgent *agent)> Task;
  Task m_pTask = nullptr;

  Condition(IAgent *agent, Task task) : IBehavior(agent), m_pTask(task) {}

  ~Condition() = default;
};
} // namespace BT

#endif // CONDITION_HPP
