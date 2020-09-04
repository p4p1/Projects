# tinder API reverse

A list of all of the requests in order

## On first boot of page
```
fetch("https://api.gotinder.com/v2/buckets?locale=en", {
    "credentials": "omit",
    "headers": {
        "accept": "application/json",
        "accept-language": "en-US,en;q=0.9",
        "app-session-id": "62fcdd7c-85b3-45a0-8585-4399c8b1db70",
        "app-session-time-elapsed": "9656",
        "app-version": "1023001",
        "content-type": "application/json",
        "persistent-device-id": "66636e8c-9a48-48e4-ab2c-914681960f2e",
        "platform": "web",
        "sec-fetch-dest": "empty",
        "sec-fetch-mode": "cors",
        "sec-fetch-site": "cross-site",
        "tinder-version": "2.30.1",
        "user-session-id": "null",
        "user-session-time-elapsed": "null",
        "x-supported-image-formats": "webp,jpeg"
    },
    "referrer": "https://tinder.com/",
    "referrerPolicy": "origin-when-cross-origin",
    "body": "{\"experiments\":[\"auth_options\",\"sms_auth_v2\",\"two_factor_auth\"],\"device_id\":\"66636e8c-9a48-48e4-ab2c-914681960f2e\"}",
    "method": "POST",
    "mode": "cors"
});
```

## On click and enter of phone info

```
fetch("https://api.gotinder.com/v3/auth/login?locale=en", {
    "credentials": "omit",
    "headers": {
        "accept": "application/json",
        "accept-language": "en-US,en;q=0.9",
        "app-session-id": "62fcdd7c-85b3-45a0-8585-4399c8b1db70",
        "app-session-time-elapsed": "242482",
        "app-version": "1023001",
        "content-type": "application/x-google-protobuf",
        "funnel-session-id": "58f7b6e34f5a2b6e",
        "persistent-device-id": "66636e8c-9a48-48e4-ab2c-914681960f2e",
        "platform": "web",
        "sec-fetch-dest": "empty",
        "sec-fetch-mode": "cors",
        "sec-fetch-site": "cross-site",
        "tinder-version": "2.30.1",
        "user-session-id": "null",
        "user-session-time-elapsed": "null",
        "x-auth-token": "",
        "x-supported-image-formats": "webp,jpeg"
    },
    "referrer": "https://tinder.com/",
    "referrerPolicy": "origin",
    "body": "st\n\r\n\u000b33652486618",
    "method": "POST",
    "mode": "cors"
});
```

## On enter of sms pin
```
fetch("https://api.gotinder.com/v3/auth/login?locale=en", {
    "credentials": "omit",
    "headers": {
        "accept": "application/json",
        "accept-language": "en-US,en;q=0.9",
        "app-session-id": "62fcdd7c-85b3-45a0-8585-4399c8b1db70",
        "app-session-time-elapsed": "345612",
        "app-version": "1023001",
        "content-type": "application/x-google-protobuf",
        "funnel-session-id": "58f7b6e34f5a2b6e",
        "persistent-device-id": "66636e8c-9a48-48e4-ab2c-914681960f2e",
        "platform": "web",
        "sec-fetch-dest": "empty",
        "sec-fetch-mode": "cors",
        "sec-fetch-site": "cross-site",
        "tinder-version": "2.30.1",
        "user-session-id": "null",
        "user-session-time-elapsed": "null",
        "x-auth-token": "",
        "x-supported-image-formats": "webp,jpeg"
    },
    "referrer": "https://tinder.com/",
    "referrerPolicy": "origin",
    "body": "\u0012\u0017\n\r\n\u000b33652486618\u0012\u0006195121",
    "method": "POST",
    "mode": "cors"
});
```
