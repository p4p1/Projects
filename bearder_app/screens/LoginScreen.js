import * as React from 'react';
import { Image, StyleSheet, Text, TouchableOpacity, View, KeyboardAvoidingView } from 'react-native';
import Form from '../components/Login/Form.js';
import Steal from '../components/Login/Steal.js';
import HelpField from '../components/Login/HelpField.js';
import Logo from '../components/Login/Logo.js';

export default class LoginScreen extends React.Component
{
  constructor(props) {
    super(props);
    this.state = {
      xauth: false,
    };

  }

  render() {
    var form;

    if (this.state.xauth == false) {
      form = <Form refresh={this.props.refresh}/>;
    } else {
      form = <Steal refresh={this.props.refresh}/>;
    }

    return (
      <KeyboardAvoidingView style={styles.container} behavior="position" enabled>
        <View style={styles.elemContain}>
          <HelpField text="WTF?" />
        </View>
        <View style={styles.elemContain}>
          <TouchableOpacity onPress={() => {this.setState({xauth: !this.state.xauth});}}>
            <Logo />
          </TouchableOpacity>
        </View>
          {form}
      </KeyboardAvoidingView>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    paddingTop: 35,
    flex: 1,
    backgroundColor: '#495057',
  },
  elemContain: {
    width: '100%',
  },
  form: {
    width: '100%',
    alignItems: 'center',
  }
});
