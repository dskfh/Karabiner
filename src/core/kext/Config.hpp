#ifndef CONFIG_HPP
#define CONFIG_HPP

namespace org_pqrs_KeyRemap4MacBook {
  class Config {
  public:
    Config() : debug(0), debug_pointing(0), debug_devel(0), initialized(0), isactive_simultaneouskeypresses_(false) {
#include "config/output/include.config.default.hpp"
    }

#include "config/output/include.config.hpp"

    // Don't put notsave_pointing_relative_to_scroll in checkbox.xml.
    // Because it is dangerous that a user changes setting.
    int notsave_pointing_relative_to_scroll;

    int get_repeat_initial_wait(void) {
      const int MINVAL = 200;
      int value = repeat_initial_wait;
      if (value < MINVAL) return MINVAL;
      return value;
    }
    int get_repeat_wait(void) {
      const int MINVAL = 5;
      int value = repeat_wait;
      if (value < MINVAL) return MINVAL;
      return value;
    }
    int get_keyoverlaidmodifier_initial_wait(void) {
      const int MINVAL = 200;
      int value = repeat_keyoverlaidmodifier_initial_wait;
      if (value < MINVAL) return MINVAL;
      return value;
    }
    int get_simultaneouskeypresses_delay(void) {
      if (! isactive_simultaneouskeypresses_) return 0;

      const int MINVAL = 5;
      const int MAXVAL = 1000;
      int value = parameter_simultaneouskeypresses_delay;
      if (value < MINVAL) return MINVAL;
      if (value > MAXVAL) return MAXVAL;
      return value;
    }
    void set_isactive_simultaneouskeypresses(bool newval) {
      isactive_simultaneouskeypresses_ = newval;
    }

    // ----------------------------------------
    int debug;
    int debug_pointing;
    int debug_devel;
    int initialized;

    enum { SOCKET_PATH_MAX = 256 };
    char socket_path[SOCKET_PATH_MAX];

  private:
    bool isactive_simultaneouskeypresses_;
  };
  extern Config config;

  void sysctl_register(void);
  void sysctl_unregister(void);
}

#endif
