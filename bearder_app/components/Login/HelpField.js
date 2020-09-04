import * as React from 'react';
import { StyleSheet, Text, TouchableOpacity, View, Modal } from 'react-native';
import WebView from 'react-native-webview';

export default class HelpField extends React.Component
{
  constructor(props) {
    super(props);
    this.state = {
      display: false,
    };

    this.displayModal = this.displayModal.bind(this);
  }

  displayModal(val) {
    this.setState({display: val});
  }

  render() {
    return (
      <View>
        <Modal
          animationType="slide"
          transparent={false}
          visible={this.state.display}
          onRequestClose={() => {
            this.displayModal(false);
        }}>
          <WebView source={{ uri: 'https://p4p1.github.io/bearder' }} />
        </Modal>
        <View style={styles.container}>
          <TouchableOpacity onPress={() => {this.displayModal(true)}}>
            <Text style={styles.helpText}>{this.props.text}</Text>
          </TouchableOpacity>
        </View>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    height: 30,
    alignItems: 'flex-end',
    marginTop: 15,
    marginRight: 15,
    marginLeft: 15,
    marginBottom: 15,
  },
  helpText: {
    color: "#FFFFFF",
    fontStyle: 'italic',
    textDecorationLine: 'underline',
    fontSize: 25,
  },
});
