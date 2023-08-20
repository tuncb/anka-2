#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#include "log.h"

static std::vector<std::string> messages;

auto log_to_screen(void *messages_ptr, const loguru::Message &message) -> void
{
  if (messages_ptr)
  {
    auto messages = *static_cast<std::vector<std::string> *>(messages_ptr);
    messages.push_back(message.message);
  }
  std::cout << message.message << "\n";
}

auto anka::init_logging(bool store_messages) -> void
{
  loguru::g_stderr_verbosity = loguru::Verbosity_OFF;
  loguru::g_internal_verbosity = loguru::Verbosity_1;
  loguru::Options logOptions;
  logOptions.verbosity_flag = nullptr;

  loguru::add_file("anka2.log", loguru::Append, loguru::Verbosity_MAX);
  auto argc = 0;
  loguru::init(argc, nullptr, logOptions);

  if (store_messages)
  {
    loguru::add_callback("screen_logger", log_to_screen, &messages, loguru::Verbosity_INFO);
  }
  else
  {
    loguru::add_callback("screen_logger", log_to_screen, nullptr, loguru::Verbosity_INFO);
  }
}

auto anka::compare_output(const std::string &filename) -> bool
{
  std::ifstream file(filename);
  if (!file)
    return false;

  std::string line;
  std::vector<std::string> correct;
  std::copy(std::istream_iterator<std::string>(file), std::istream_iterator<std::string>(),
            std::back_inserter(correct));

  return messages == correct;
}
