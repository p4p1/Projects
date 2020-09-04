import * as React from 'react';
import { Image, Platform, StyleSheet, TouchableOpacity, View } from 'react-native';

export default class MessageButton extends React.Component
{
  constructor(props) {
    super(props);
  }

  render() {
    return (
        <View style={styles.container}>
          <TouchableOpacity style={styles.opacity} onPress={this.props.run}>
            <Image style={styles.buttonNext} source={require('./../../assets/images/buttons/send.png')} />
          </TouchableOpacity>
        </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    width: 45,
    height: 45,
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
  buttonNext: {
    width: 45,
    height: 45,
  },
});
