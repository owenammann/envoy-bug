A minimal setup to reproduce a crash in Envoy (v1.21) using bazel 4.2.2-homebrew as a build tool.

Steps to reproduce:

1. `cd my_filter`
2. `bazel build my_filter.wasm`
3. `cd  ..`
4. `envoy -c envoy.yaml`
5. Send a request to localhost:10000 with `x-my-header: B`. Should receive HTTP 200 and the envoy homepage.
    `curl --location --request GET 'http://localhost:10000/' \
--header 'x-my-header: B'`

6. Send the same request without `x-my-header`. Will receive an `HTTP 503` error.
    `curl --location --request GET 'http://localhost:10000/'`

7. Now, send the request again as in step 5 (with `x-my-header`)
    `curl --location --request GET 'http://localhost:10000/' \
--header 'x-my-header: B'`

Expected behavior: Receive an `HTTP 200` and the envoy homepage.
Actual behavior: Receive an `HTTP 503` error. We believe this is because the `WASM V8` VM is not recoverring from the runtime error. We also tried with `fail_open: true`. Even though we get 200 each time, we do not see any wasm logs after having sent at least one request without `x-my-header`.