#include "logger.h"

void logger_init(struct Logger* log, int level)
{
  // Defensive check
  if (log == 0) return;

  logger_set_level(log, level);
  logger_set_stream(log, stdout);
}

void logger_set_level(struct Logger* log, int level)
{
  // Defensive check
  if (log == 0) return;

  log->level = level;
}

void logger_set_stream(struct Logger* log, FILE* stream)
{
  // Defensive check
  if (log == 0) return;

  log->output = stream;
}

struct Logger* logger_get_global_log()
{
  static struct Logger log;
  static int firstTime = 0;

  if (firstTime == 0)
  {
    logger_init(&log, LOGLEVEL_WARNING);
    firstTime = 1;
  }

  return &log;
}

int _logger_generic(struct Logger* log, int level,
  const char* prefix,
  const char* file_name, int line_num,
  const char* fmt, ...)
{
  // Defensive check
  if (log == 0) return 0;

  if (log->level <= level)
  {
    fprintf(log->output, "%s %s: %d -- ", prefix, file_name, line_num);
    va_list args;
    int count;
    va_start(args, fmt);
    count = vfprintf(log->output, fmt, args);
    va_end(args);
    return count;
  }
  return 0;
}
