import * as React from 'react';
import { TextInput, StyleSheet, View } from 'react-native';

export default class TextField extends React.Component
{
  constructor(props) {
    super(props);
    this.state = {
      type: 'default',
      style: styles.container,
      styleText: styles.input,
    };

    if (this.props.type !== undefined) {
      this.state.type = this.props.type;
    }
    if (this.props.style !== undefined) {
      this.state.style = this.props.style;
    }
    if (this.props.styleText !== undefined) {
      this.state.styleText = this.props.styleText;
    }
  }

  render() {
    return (
        <View style={this.state.style}>
          <TextInput style={this.state.styleText}
            onChangeText={this.props.run}
            placeholder={this.props.text}
            keyboardType={this.state.type}
          />
        </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    width: '70%',
    height: 60,
    marginTop: 15,
    marginRight: 15,
    marginLeft: 15,
    marginBottom: 15,
  },
  input: {
    width: '100%',
    height: '100%',
    color: "#FFFFFF",
    borderBottomWidth: 1,
    borderColor: '#c70082',
    fontSize: 35,
  }
});
