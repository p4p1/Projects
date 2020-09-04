import * as React from 'react';
import { StyleSheet, View } from 'react-native';

import TextButton from '../Text/TextButton.js';
import TextField from '../Text/TextField.js';

export default class Steal extends React.Component
{
  constructor(props) {
    super(props);
    this.state = {
      xauth_str: "",
    }

    this.setXauth = this.setXauth.bind(this);
    this.forceAuth = this.forceAuth.bind(this);
  }

  forceAuth(val) {
    alert("Xauth set to: " + val);
    global.xauth=val;
    this.props.refresh();
  }
  setXauth(dat) {
    this.setState({xauth_str: dat});
  }

  render() {
    return (
      <View style={styles.container}>
        <TextField type="default" text="Enter xauth" run={this.setXauth} />
        <TextButton text="STEAL" run={() => {this.forceAuth(this.state.xauth_str)}} />
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
