import * as React from 'react';
import { StyleSheet, Text, View, Image } from 'react-native';

export default class Yup extends React.Component
{
  constructor(props) {
    super(props);
  }

  render() {
    return (
      <View style={styles.container}>
        <Image style={styles.image} source={require("../../assets/images/buttons/like.png")}/>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    width: 30,
    height: 30,
  },
  image: {
    width: 30,
    height: 30,
  }
});
