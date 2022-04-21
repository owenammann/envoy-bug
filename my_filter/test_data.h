#include "nlohmann/json.hpp"
using json = nlohmann::json;
namespace test_data
{
    const json mpe_data_1 = R"(
    [
        {
            "id": "1",
            "type": "fee",
            "attributes": {
                "type": "markup",
                "amount": [
                    20.0
                ],
                "amountType": "percentage",
                "label": "Markup Fee",
                "inventory": "memberdb",
                "segments": [
                    {
                        "amount": [
                            20.0
                        ]
                    }
                ]
            }
        },
        {
            "id": "2",
            "type": "fee",
            "attributes": {
                "type": "buyer",
                "amount": [
                    20.0
                ],
                "amountType": "percentage",
                "label": "Service Fees",
                "minimum": {
                    "amount": 32.0,
                    "currencyCode": ""
                },
                "segments": [
                    {
                        "amount": [
                            20.0
                        ]
                    }
                ]
            }
        },
        {
            "id": "3",
            "type": "fee",
            "attributes": {
                "type": "markup",
                "amount": [
                    21.0
                ],
                "amountType": "percentage",
                "label": "Markup Fee 2",
                "inventory": "tnowbroker",
                "segments": [
                    {
                        "amount": [
                            21.0
                        ]
                    }
                ]
            }
        }
    ]
    )"_json;
    const json mpe_data_2 = R"(
    [
        {
        "id": "1",
        "type": "fee",
        "attributes": {
            "type": "buyer",
            "amount": [
            20
            ],
            "amountType": "percentage",
            "label": "Service Fees",
            "minimum": {
            "amount": 5,
            "currencyCode": "USD"
            }
        }
        },
        {
        "id": "2",
        "type": "fee",
        "attributes": {
            "type": "markup",
            "amount": [
            2
            ],
            "amountType": "percentage",
            "label": "Markup Fees",
            "segments": [
            {
                "amount": [
                3.0
                ],
                "priceRange": {
                "min": 0.0,
                "max": 50.0
                }
            },
            {
                "amount": [
                4.0
                ],
                "priceRange": {
                "min": 50.0,
                "max": 100.0
                }
            },
            {
                "amount": [
                5.0
                ],
                "priceRange": {
                "min": 100.0,
                "max": 999999.0
                }
            }
            ]
        }
        }
    ]
    )"_json;
}
