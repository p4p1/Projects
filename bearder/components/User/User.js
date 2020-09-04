import * as React from 'react';
import { StyleSheet, Modal, Text, View, Image, ImageBackground, ScrollView, TouchableOpacity } from 'react-native';

export default  class User extends React.Component
{
  constructor(props) {
    super(props);
    this.state = {
      modalVisible: false,
      current_img_id: 0,
    }
    this.setModal = this.setModal.bind(this);
    this.next_img = this.next_img.bind(this);
    this.prev_img = this.prev_img.bind(this);
  }

  setModal(val) {
    this.setState({modalVisible: val});
    this.setState({current_img_id: 0});
    console.log(this.props.id);
  }
  next_img() {
    if (this.state.current_img_id < this.props.id.person.photos.length - 1) {
      this.setState({current_img_id: this.state.current_img_id+1});
    }
  }
  prev_img() {
    if (this.state.current_img_id > 0) {
      this.setState({current_img_id: this.state.current_img_id-1});
    }
  }

  render() {
    if (this.props.id.person == undefined) {
      return (<View></View>);
    }
    return (
      <View>
        <Modal
          animationType="slide"
          visible={this.state.modalVisible}
          onRequestClose={() => {
            this.setModal(false);
          }}
          transparent={true}
        >
          <View style={styles.containerModal}>
            <ScrollView style={styles.Modal}>
              <ImageBackground style={styles.thumbnailModal} source={{uri: this.props.id.person.photos[this.state.current_img_id].processedFiles[0].url}}>
                <TouchableOpacity style={styles.prev_img} onPress={this.prev_img}>
                </TouchableOpacity>
                <TouchableOpacity style={styles.next_img} onPress={this.next_img}>
                </TouchableOpacity>
              </ImageBackground>
              <View style={styles.modalContent}>
                <Text style={styles.header}>{this.props.id.person.name}</Text>
                <Text>{this.props.id.person.bio}</Text>
              </View>
            </ScrollView>
          </View>
        </Modal>
        <View style={styles.container}>
          <TouchableOpacity onPress={() => {this.setModal(true)}}>
            <Image style={styles.thumbnail} source={{uri: this.props.id.person.photos[0].processedFiles[0].url}} />
          </TouchableOpacity>
        </View>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    width: '100%',
    //position: 'absolute',
    //bottom: '10%',
    backgroundColor: '#c70082',
  },
  thumbnail: {
    width: 100,
    height: 150,
  },
  thumbnailModal: {
    width: '100%',
    height: 450,
    flexDirection: 'row',
  },
  Modal : {
    width: '80%',
    height: '90%',
    backgroundColor: 'white',
  },
  containerModal: {
    justifyContent: 'center',
    alignItems: 'center',
  },
  next_img: {
    width: '50%',
    height: '100%',
  },
  prev_img: {
    width: '50%',
    height: '100%',
  },
  header: {
    fontWeight: "bold",
    fontSize: 30,
  },
  modalContent: {
    paddingLeft: 15,
    paddingRight: 15,
  },
});
