import * as React from 'react';
import { Image, Platform, StyleSheet, Text, TouchableOpacity, View } from 'react-native';

export default class TextButton extends React.Component
{
  constructor(props) {
    super(props);
  }

  render() {
    return (
        <View style={styles.container}>
          <TouchableOpacity style={styles.opacity} onPress={this.props.run}>
            <Text style={styles.buttonText}>{this.props.text}</Text>
            <Image style={styles.buttonNext} source={require('./../../assets/images/buttons/next_white.png')} />
          </TouchableOpacity>
        </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    width: '70%',
    height: 70,
    backgroundColor: '#c70082',
    flexDirection: 'row',
    alignItems: 'center',
    marginTop: 15,
    marginRight: 15,
    marginLeft: 15,
    marginBottom: 15,
  },
  opacity: {
    flexDirection: 'row',
    alignItems: 'center',
  },
  buttonText: {
    paddingLeft: '15%',
    paddingRight: 50,
    color: "#FFFFFF",
    fontSize: 45,
  },
  buttonNext: {
    width: 45,
    height: 45,
  },
});
