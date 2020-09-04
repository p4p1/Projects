import React from 'react';
import { StyleSheet, Text, View } from 'react-native';

import LoginScreen from './screens/LoginScreen';
import HomeScreen from './screens/HomeScreen';

export default class App extends React.Component
{
  constructor(props) {
    super(props);
    this.state = {
      refresh: false,
      tinder_working: false
    };

    this.refreshMe = this.refreshMe.bind(this);
  }

  refreshMe() {
    this.setState({refresh: !this.state.refresh});
  }

  componentDidMount() {
    global.tinder_version="2.18.0";
    fetch("https://api.gotinder.com/v2/buckets?locale=en", {
      method: "POST",
      headers: {
        Accept: 'application/json',
        'Content-Type': 'application/json',
        'platform': 'web',
        'tinder-version': global.tinder_version,
        'x-supported-image-formats': 'jpeg',
      },
      body: JSON.stringify({
          experiments:[
           "auth_options",
           "sms_auth_v2",
           "two_factor_auth"
          ],
          device_id:"null"
      }),
    }).then((response) => response.json()).then((json) => {
      if (json.meta.status == 200) {
        this.setState({tinder_working: true});
      }
      console.log(json);
      console.log(this.state.tinder_working);
    }).catch((error) => console.error(error));
  }

  render() {
    console.log("global.tinder_data:");
    console.log(global.tinder_data);
    console.log("global.xauth:");
    console.log(global.xauth);
    if (this.state.tinder_working === false) {
      return (
        <View style={styles.container}>
          <Text>Not Working</Text>
        </View>
      );
    }
    return (
      <View style={styles.container}>
        {
          (global.xauth == undefined && global.tinder_data == undefined) ?
            <LoginScreen refresh={this.refreshMe}/> :
            <HomeScreen refresh={this.refreshMe} />
        }
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
  }
});
