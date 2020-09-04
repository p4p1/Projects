import * as React from 'react';
import { View, StyleSheet, TouchableOpacity, Image } from 'react-native';

export default class Logo extends React.Component
{
  constructor(props) {
    super(props);
  }

  render() {
    return (
      <View style={styles.container}>
        <Image style={styles.main} source={require('./../../assets/images/icon.png')} />
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    paddingTop: 25,
    marginRight: 15,
    marginLeft: 15,
    height: 400,
  },
  main: {
    width: '100%',
    height: 350,
  }
});
