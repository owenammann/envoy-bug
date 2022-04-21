#include <string>

#include "proxy_wasm_intrinsics.h"

class MyContext : public Context
{
public:
  explicit MyContext(uint32_t id, RootContext *root) : Context(id, root) {}

  FilterHeadersStatus onRequestHeaders(uint32_t, bool) override;
};