import * as React from 'react';
import { StyleSheet, View } from 'react-native';
import TextButton from '../Text/TextButton.js';
import TextField from '../Text/TextField.js';

export default class Form extends React.Component
{
  constructor(props) {
    super(props);
    this.state = {
      number: "",
      sms_code: "",
      sms_sent: false,
    }
    this.sendPhoneNumber = this.sendPhoneNumber.bind(this);
    this.sendSmsCode = this.sendSmsCode.bind(this);
    this.handleNumber = this.handleNumber.bind(this);
    this.handleSms = this.handleSms.bind(this);
  }

  sendPhoneNumber(dat) {
    fetch("https://api.gotinder.com/v2/auth/sms/send?auth_type=sms&locale=en", {
      credentials: "omit",
      headers: {
        accept: "application/json",
        "accept-encoding": "gzip, deflate, br",
        "accept-language": "en-US,en;q=0.9",
        "app-session-id": "a27bb1ea-ac87-46dc-9a49-ef8b3d03ec1f",
        "app-session-time-elapsed": "16669",
        "app-version": "1021800",
        "persistent-device-id": "0d4f3e12-ca69-48f2-9797-9728f00cd1b9",
        platform: "web",
        referer: "https://tinder.com/",
        "sec-fetch-mode": "cors",
        "sec-fetch-site": "cross-site",
        "tinder-version": "2.18.0",
        "user-agent":
          "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.72 Safari/537.36 Vivaldi/2.9.1705.31",
        "user-session-id": "64e2cb41-6eb5-4b2e-a512-a76b6e68c7f2",
        "user-session-time-elapsed": "16347",
        "x-supported-image-formats": "webp,jpeg",
        "Content-Type": "application/json"
      },
      referrer: "https://tinder.com/",
      referrerPolicy: "origin",
      body: `{\"phone_number\":\"${dat}\"}`,
      method: "POST",
      mode: "cors"
    }).then((response) => response.json()).then((json) => {
      console.log(json);
      this.setState({sms_sent: json.data.sms_sent});
    }).catch((error) => console.error(error));
  }
  sendSmsCode(dat) {
    console.log("number", this.state.number, "code", dat);
    fetch(
      "https://api.gotinder.com/v2/auth/sms/validate?auth_type=sms&locale=en",
      {
        credentials: "omit",
        headers: {
          accept: "application/json",
          "accept-encoding": "gzip, deflate, br",
          "accept-language": "en-US,en;q=0.9",
          "app-session-id": "a27bb1ea-ac87-46dc-9a49-ef8b3d03ec1f",
          "app-session-time-elapsed": "16669",
          "app-version": "1021800",
          "persistent-device-id": "0d4f3e12-ca69-48f2-9797-9728f00cd1b9",
          platform: "web",
          referer: "https://tinder.com/",
          "sec-fetch-mode": "cors",
          "sec-fetch-site": "cross-site",
          "tinder-version": "2.18.0",
          "user-agent":
            "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.72 Safari/537.36 Vivaldi/2.9.1705.31",
          "user-session-id": "64e2cb41-6eb5-4b2e-a512-a76b6e68c7f2",
          "user-session-time-elapsed": "16347",
          "x-supported-image-formats": "webp,jpeg",
          "Content-Type": "application/json"
        },
        referrer: "https://tinder.com/",
        referrerPolicy: "origin",
        body: `{\"otp_code\":\"${dat}\",\"phone_number\":\"${this.state.number}\",\"is_update\":false}`,
        method: "POST",
        mode: "cors"
    }).then((response) => response.json()).then((respJson) => {
      token_refresh = respJson.data.refresh_token;
      console.log(token_refresh);
      fetch("https://api.gotinder.com/v2/auth/login/sms?locale=en", {
        credentials: "omit",
        headers: {
          accept: "application/json",
          "accept-encoding": "gzip, deflate, br",
          "accept-language": "en-US,en;q=0.9",
          "app-session-id": "a27bb1ea-ac87-46dc-9a49-ef8b3d03ec1f",
          "app-session-time-elapsed": "16669",
          "app-version": "1021800",
          "persistent-device-id": "0d4f3e12-ca69-48f2-9797-9728f00cd1b9",
          platform: "web",
          referer: "https://tinder.com/",
          "sec-fetch-mode": "cors",
          "sec-fetch-site": "cross-site",
          "tinder-version": "2.18.0",
          "user-agent":
            "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.72 Safari/537.36 Vivaldi/2.9.1705.31",
          "user-session-id": "64e2cb41-6eb5-4b2e-a512-a76b6e68c7f2",
          "user-session-time-elapsed": "16347",
          "x-supported-image-formats": "webp,jpeg",
          "Content-Type": "application/json"
        },
        referrer: "https://tinder.com/",
        referrerPolicy: "origin",
        body: `{\"refresh_token\":\"${token_refresh}\",\"phone_number\":\"${this.state.number}\"}`,
        method: "POST",
        mode: "cors"
      })
.then((response) => response.json()).then((respJson) => {
        global.tinder_data = respJson;
        global.xauth = respJson.data.api_token;
        this.props.refresh();
      }).catch((error) => { console.error(error); });
    }).catch((error) => { console.error(error); });
  }

  handleNumber(num) {
    this.setState({number: num});
  }
  handleSms(sms) {
    this.setState({sms_code: sms});
  }

  render() {
    var form;

    if (this.state.sms_sent == true) {
      form = <View style={styles.container}><TextField type="numeric" text="SMS Code" run={this.handleSms} />
          <TextButton text="LOGIN" run={() => {this.sendSmsCode(this.state.sms_code)}} /></View>;
    } else {
      form = <View style={styles.container}><TextField type="numeric" text="phone number" run={this.handleNumber} />
          <TextButton text="NEXT" run={() => {this.sendPhoneNumber(this.state.number)}} /></View>;
    }
    return (
      <View style={styles.container}>
        {form}
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    width: '100%',
    alignItems: 'center',
  },
});
