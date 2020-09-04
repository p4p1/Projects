import * as React from 'react';
import { AsyncStorage, StyleSheet, Modal, Text, View, ImageBackground, Image,ScrollView, TouchableOpacity } from 'react-native';

class Person extends React.Component
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
    this.like = this.like.bind(this);
    this.dislike = this.dislike.bind(this);
  }

  setModal(val) {
    this.setState({modalVisible: val});
    this.setState({current_img_id: 0});
    console.log(this.props.id);
  }
  next_img() {
    if (this.state.current_img_id < this.props.id.user.photos.length - 1) {
      this.setState({current_img_id: this.state.current_img_id+1});
    }
  }
  prev_img() {
    if (this.state.current_img_id > 0) {
      this.setState({current_img_id: this.state.current_img_id-1});
    }
  }
  async like() {
    fetch(`https://api.gotinder.com/like/${this.props.id.user._id}`, {
      credentials: "omit",
      headers: {
        accept: "application/json",
        "accept-encoding": "gzip, deflate, br",
        "accept-language": "en-US,en;q=0.9",
        "app-session-id": "a27bb1ea-ac87-46dc-9a49-ef8b3d03ec1f",
        "app-session-time-elapsed": "16669",
        "app-version": "1021800",
        "persistent-device-id": "0d4f3e12-ca69-48f2-9797-9728f00cd1b9",
        platform: "web",
        referer: "https://tinder.com/",
        "sec-fetch-mode": "cors",
        "sec-fetch-site": "cross-site",
        "tinder-version": "2.18.0",
        "user-agent":
          "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.72 Safari/537.36 Vivaldi/2.9.1705.31",
        "user-session-id": "64e2cb41-6eb5-4b2e-a512-a76b6e68c7f2",
        "user-session-time-elapsed": "16347",
        "x-supported-image-formats": "webp,jpeg",
        "Content-Type": "application/json",
        "x-auth-token": `${global.xauth}`
      },
      referrer: "https://tinder.com/",
      referrerPolicy: "origin",
      body: null,
      method: "GET",
      mode: "cors"
    })
      .then(result => result.json())
      .then(json => {
        console.log(json);
        this.setState({match: json.match});
      });
     try {
      await AsyncStorage.removeItem(this.props.id.user.name);
    } catch (error) {
      // Error retrieving data
      console.log("Fuck2");
      console.log(error);
    }
    console.log(this.props.ref);
  }
  async dislike() {
    fetch(`https://api.gotinder.com/pass/${this.props.id.user._id}`, {
      credentials: "omit",
      headers: {
        accept: "application/json",
        "accept-encoding": "gzip, deflate, br",
        "accept-language": "en-US,en;q=0.9",
        "app-session-id": "a27bb1ea-ac87-46dc-9a49-ef8b3d03ec1f",
        "app-session-time-elapsed": "16669",
        "app-version": "1021800",
        "persistent-device-id": "0d4f3e12-ca69-48f2-9797-9728f00cd1b9",
        platform: "web",
        referer: "https://tinder.com/",
        "sec-fetch-mode": "cors",
        "sec-fetch-site": "cross-site",
        "tinder-version": "2.18.0",
        "user-agent":
          "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.72 Safari/537.36 Vivaldi/2.9.1705.31",
        "user-session-id": "64e2cb41-6eb5-4b2e-a512-a76b6e68c7f2",
        "user-session-time-elapsed": "16347",
        "x-supported-image-formats": "webp,jpeg",
        "Content-Type": "application/json",
        "x-auth-token": `${global.xauth}`
      },
      referrer: "https://tinder.com/",
      referrerPolicy: "origin",
      body: null,
      method: "GET",
      mode: "cors"
    })
      .then(result => result.json())
     .then(json => console.log(json));
     try {
      await AsyncStorage.removeItem(this.props.id.user.name);
    } catch (error) {
      // Error retrieving data
      console.log("Fuck2");
      console.log(error);
    }
    this.props.ref();
  }

  render() {
    let data=<View></View>;

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
              <ImageBackground style={styles.thumbnailModal} source={{uri: this.props.id.user.photos[this.state.current_img_id].processedFiles[0].url}}>
                <TouchableOpacity style={styles.prev_img} onPress={this.prev_img}>
                </TouchableOpacity>
                <TouchableOpacity style={styles.next_img} onPress={this.next_img}>
                </TouchableOpacity>
              </ImageBackground>
              <View style={styles.modalContent}>
                <Text style={styles.header}>{this.props.id.user.name}</Text>
                <Text>{this.props.id.user.bio}</Text>
                <View style={styles.like_pass}>
                  <TouchableOpacity onPress={this.like}>
                    <Image style={{width: 60, height: 60}} source={require("../../assets/images/buttons/like.png")} />
                  </TouchableOpacity>
                  <TouchableOpacity onPress={this.dislike}>
                    <Image style={{width: 60, height: 60}} source={require("../../assets/images/buttons/dislike.png")} />
                  </TouchableOpacity>
                </View>
              </View>
            </ScrollView>
          </View>
        </Modal>
        <TouchableOpacity onPress={() => {this.setModal(true)}}>
          <ImageBackground style={styles.thumbnail} source={{uri: this.props.url}}>
            {data}
          </ImageBackground>
        </TouchableOpacity>
      </View>
    );
  }
}

export default  class Saved extends React.Component
{
  constructor(props) {
    super(props);
    this.state = {
      data : [],
      refresh: false,
    };
    this.refresher = this.refresher.bind(this);
  }

  async componentDidMount() {
    var keys;
    var tmp;
    try {
      keys = await AsyncStorage.getAllKeys();
      if (keys !== null) {
        // We have data!!
        console.log("data");
        console.log(keys);
      }
    } catch (error) {
      // Error retrieving data
      console.log("Fuck2");
      console.log(error);
    }
    console.log("--------------------------------");
    for (let i = 0; i < keys.length; i++) {
      try {
        tmp = await AsyncStorage.getItem(keys[i]);
        if (tmp !== null) {
          // We have data!!
          console.log("data");
          console.log(tmp);
          this.state.data[i] = JSON.parse(tmp);
        }
      } catch (error) {
        // Error retrieving data
        console.log("Fuck2");
        console.log(error);
      }
    }
    this.setState({refresh: !this.state.refresh});
  }

  refresher() {
    this.setState({refresh: !this.state.refresh});
  }

  render() {
    var data=<Text style={styles.loner}>No one yet...</Text>;;
    if (this.state.data != undefined && this.state.data.length > 0) {
      data=this.state.data.map((item) => {
        return(<Person url={item.user.photos[0].processedFiles[0].url} id={item} ref={this.refresher} />);
            });
    }
    return (
      <View style={styles.container}>
        <ScrollView horizontal={true}>
          {data}
        </ScrollView>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    width: '100%',
    height: 150,
    //position: 'absolute',
    //bottom: '10%',
    backgroundColor: '#c70082',
  },
  thumbnail: {
    width: 100,
    height: 150,
  },
  loner: {
    width: 100,
    fontWeight: "bold",
    justifyContent: 'center',
    alignItems: 'center',
  },

  CircleShapeView: {
        width: 10,
        height: 10,
        borderRadius: 150/2,
        backgroundColor: '#00BCD4'
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
  like_pass: {
    flexDirection: 'row',
  }
});
