#ifndef SCOPE_EXIT
#define SCOPE_EXIT

// A basic implementation of std::experimental::scope_exit
template <typename Fn>
class scope_exit
{
public:
  explicit scope_exit(Fn&& fn) noexcept
    : fn_(std::move(fn)),
      active_(true)
  {
  }

  scope_exit(scope_exit&& that) noexcept
    : fn_(std::move(that.fn_)),
      active_(that.active_)
  {
    that.release();
  }

  scope_exit(const scope_exit&) = delete;
  scope_exit& operator=(const scope_exit&) = delete;

  ~scope_exit()
  {
    if (active_) {
      fn_();
    }
  }

  void release() noexcept
  {
    active_ = false;
  }

private:
  Fn fn_;
  bool active_;
};

template <typename Fn>
scope_exit<Fn> make_scope_exit(Fn&& fn) noexcept
{
  return scope_exit<Fn>(std::move(fn));
}

#endif
