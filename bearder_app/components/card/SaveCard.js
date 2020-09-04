import * as React from 'react';
import { StyleSheet, Text, View, ImageBackground, ScrollView, TouchableOpacity } from 'react-native';

export default class SaveCard extends React.Component
{
  constructor(props) {
    super(props);
    this.state = {
      data : undefined,
    };
  }

  render() {
    return (
      <View style={styles.container}>
        <Text>Saved</Text>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    width: '100%',
    height: 150,
    position: 'absolute',
    bottom: '10%',
    //backgroundColor: '#c70082',
    backgroundColor: '#495057',
  },
});
