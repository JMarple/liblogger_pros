# liblogger for PROS2

The liblogger library for PROS contains a simple way to turn on and off logging streams at varying levels.  It is especially useful for developing code where file and line descriptions are printed out along with the message. Being able to turn on and off debug messages at runtime is also important when developing libraries for PROS.

Author: Justin Marple
Contact: justinjmarple@gmail.com

---

The logger contains the following API calls:

 - void logger_init(struct Logger* log, int level);
 - void logger_set_level(struct Logger* log, int level);
 - void logger_set_stream(struct Logger* log, FILE* stream);
 - int logger_debug(struct Logger* log, const char* fmt, ...);
 - int logger_info(struct Logger* log, const char* fmt, ...);
 - int logger_warning(struct Logger* log, const char* fmt, ...);
 - int logger_error(struct Logger* log, const char* fmt, ...);
 - int logger_critical(struct Logger* log, const char* fmt, ...);

A quick example:
```c
logger_init(&log, LOGLEVEL_WARNING);

// Printed to the console screen, as the logging includes
// warning messages and above
logger_warning(&log, "A warning message here\n");

// This is ignored, as info is below the warning logging level
logger_info(&log, "Some info here: %f\n", 3.1415);
```
