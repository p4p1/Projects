'use strict';

import React from 'react';
import {StyleSheet, Text, AsyncStorage, View, Image, ImageBackground, Modal, TouchableOpacity, ScrollView} from 'react-native';

import SwipeCards from 'react-native-swipe-cards';

import Likes from '../components/card/Likes';
import Saved from '../components/card/Saved';
import Yup from '../components/card/Yup';
import Nop from '../components/card/Nop';
import Messages from '../components/messages/messages';

export class Card extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      modalVisible: false,
      current_img_id: 0,
    }
    this.setModal = this.setModal.bind(this);
    this.next_img = this.next_img.bind(this);
    this.prev_img = this.prev_img.bind(this);
    this._storeData = this._storeData.bind(this);
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
  _storeData = async () => {
    try {
      await AsyncStorage.setItem(
        this.props.name,
        JSON.stringify(this.props.id)
      );
    } catch (error) {
      // Error saving data
      console.log("fuck");
      console.log(error);
    }

  };

  render() {
    if (this.props.id == undefined) {
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
              <ImageBackground style={styles.thumbnailModal} source={{uri: this.props.id.user.photos[this.state.current_img_id].processedFiles[0].url}}>
                <TouchableOpacity style={styles.prev_img} onPress={this.prev_img}>
                </TouchableOpacity>
                <TouchableOpacity style={styles.next_img} onPress={this.next_img}>
                </TouchableOpacity>
              </ImageBackground>
              <View style={styles.modalContent}>
                <Text style={styles.header}>{this.props.name}</Text>
                <Text>{this.props.id.user.bio}</Text>
                <TouchableOpacity onPress={this._storeData}>
                  <Image style={{width: 60, height: 60}} source={require("../assets/images/buttons/save.png")} />
                </TouchableOpacity>
              </View>
            </ScrollView>
          </View>
        </Modal>
        <TouchableOpacity onPress={() => {this.setModal(true)}}>
          <View style={styles.card}>
            <ImageBackground style={styles.thumbnail} source={{uri: this.props.image}}>
              <Text style={styles.text}>{this.props.name}</Text>
            </ImageBackground>
          </View>
        </TouchableOpacity>
      </View>
    )
  }
}

//test-id:5e97320b1b3176010061f38c
export class NoMoreCards extends React.Component {
  constructor(props) {
    super(props);
  }

  render() {

    return (
      <View style={styles.noMoreCards}>
        <Text>Loading...</Text>
      </View>
    )
  }
}

export default class HomeScreen extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      cards: undefined,
      outOfCards: false,
      match: false,
      lastRefresh: Date(Date.now()).toString(),
    }

    this.handleYup = this.handleYup.bind(this);
    this.refreshme = this.refreshme.bind(this);
  }

  refreshme() {
     this.setState({ lastRefresh: Date(Date.now()).toString() })
    console.log('yo');
  }

  componentDidMount() {
    var tmp_card = [];
    fetch("https://api.gotinder.com/recs", {
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
        for (let i = 0; i < json.results.length; i++) {
          tmp_card[i] = {name:json.results[i].user.name, image: json.results[i].user.photos[0].processedFiles[0].url, id: json.results[i]}
        }
        this.setState({cards: tmp_card});
      });
  }

  handleYup (card) {
    fetch(`https://api.gotinder.com/like/${card.id.user._id}`, {
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
  }

  handleNope (card) {
    fetch(`https://api.gotinder.com/pass/${card.id.user._id}`, {
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
  }

  cardRemoved (index) {
    console.log(`The index is ${index}`);

    let CARD_REFRESH_LIMIT = 3

    if (this.state.cards.length - index <= CARD_REFRESH_LIMIT + 1) {
      var tmp_card = [];
      fetch("https://api.gotinder.com/recs", {
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
          console.log("HERER");
          this.setState({cards: [ ]});
          for (let i = 0; i < json.results.length; i++) {
            tmp_card[i] = {name:json.results[i].user.name, image: json.results[i].user.photos[0].processedFiles[0].url, data: json.results[i]}
            this.setState({cards: [...this.state.cards, tmp_card[i]]});
          }
        });

    }

  }

  render() {
    var mdr;
    if (this.state.match === false) {
      mdr = <View style={styles.banner}></View>;
    } else {
      mdr = <View style={styles.banner2}></View>;
    }
    return (
        <ScrollView style={styles.container}>
          <TouchableOpacity style={styles.banner} onPress={this.refreshme}>
            {mdr}
          </TouchableOpacity>
          <View style={styles.swiper}>
            <SwipeCards
              stack={true}
              cards={this.state.cards}
              loop={false}

              renderCard={(cardData) => <Card {...cardData} />}
              renderNoMoreCards={() => <NoMoreCards />}
              showYup={true}
              yupView={<Yup />}
              showNope={true}
              noView={<Nop />}
              dragY={false}

              handleYup={this.handleYup}
              handleNope={this.handleNope}
              cardRemoved={this.cardRemoved.bind(this)}
            />
          </View>
          <Text style={styles.main_header}>People that liked you:</Text>
          <Likes />
          <Text style={styles.main_header}>People that you saved:</Text>
          <Saved />
          <Text style={styles.main_header}>Messages:</Text>
          <Messages />
        </ScrollView>
    )
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: 20,
    backgroundColor: '#495057',
  },
  banner: {
    height: 50,
    width: '100%',
    backgroundColor: 'black',
    marginBottom: 10,
  },
  banner2: {
    height: 50,
    backgroundColor: '#c70082',
    width: '100%',
    marginBottom: 10,
  },
  card: {
    alignItems: 'center',
    borderRadius: 5,
    overflow: 'hidden',
    borderColor: 'grey',
    borderWidth: 1,
    elevation: 1,
  },
  thumbnail: {
    width: 300,
    height: 450,
    flexDirection: 'row',
  },
  thumbnailModal: {
    width: '100%',
    height: 450,
    flexDirection: 'row',
  },
  text: {
    color: '#c70082',
    fontWeight: "bold",
    fontSize: 20,
    width: '100%'
  },
  noMoreCards: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  swiper: {
    height: 500,
  },
  Modal : {
    width: '80%',
    height: '90%',
    backgroundColor: '#c70082',
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
  main_header: {
    color: 'white',
    fontWeight: "bold",
    fontSize: 15,
    marginTop: 15,
  }
})
