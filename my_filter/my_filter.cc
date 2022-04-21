// NOLINT(namespace-envoy)
#include <string>
#include <unordered_map>
#include <cstring>
#include <algorithm>

#include "my_filter.h"

static RegisterContextFactory register_MyContext(CONTEXT_FACTORY(MyContext));


FilterHeadersStatus MyContext::onRequestHeaders(uint32_t, bool)
{
  //parse the request and format the call to mpe
  auto my_header = getRequestHeader("x-my-header")->toString();

  auto source = my_header.at(0) == 'A' ? "Alpha" : "Beta";
  logInfo("Did not crash");
  return FilterHeadersStatus::Continue;
}