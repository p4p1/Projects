import * as React from 'react';
import { StyleSheet, Modal, Text, Image, View, ImageBackground, ScrollView, TouchableOpacity } from 'react-native';

import TextField from '../Text/TextField.js';
import MessageButton from '../Text/MessageButton.js';

import User from '../User/User.js';

function isURL(string) {
    var res = string.match(/(http(s)?:\/\/.)?(www\.)?[-a-zA-Z0-9@:%._\+~#=]{2,256}\.[a-z]{2,6}\b([-a-zA-Z0-9@:%_\+.~#?&//=]*)/g);
    return (res !== null)
};


class Msg extends React.Component
{
  constructor(props) {
    super(props);
    this.state = {
      modalVisible: false,
      message: "",
      refresh: false,
    }
    this.setModal = this.setModal.bind(this);
    this.saveMessage = this.saveMessage.bind(this);
    this.sendMessage = this.sendMessage.bind(this);
  }

  setModal(val) {
    this.setState({modalVisible: val});
    console.log(this.props.id);
  }

  saveMessage(val) {
    this.setState({message: val});
  }

  sendMessage() {
    console.log(this.state.message);
    console.log(this.props.id.person._id);
    var myHeaders = {
      accept: "application/json",
      "accept-encoding": "gzip, deflate, br",
      "accept-language": "en-US,en;q=0.9",
      "app-session-id": "a27bb1ea-ac87-46dc-9a49-ef8b3d03ec1f",
      "app-session-time-elapsed": "16669",
      "app-version": "1021800",
      origin: "https://tinder.com",
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
      "x-auth-token": global.xauth,
      "x-supported-image-formats": "webp,jpeg",
      "Content-Type": "application/json"
    };

    var raw = JSON.stringify({ message: this.state.message });

    var requestOptions = {
      method: "POST",
      headers: myHeaders,
      body: raw,
      redirect: "follow"
    };

    fetch(
      `https://api.gotinder.com/user/matches/${this.props.id.id}`,
      requestOptions
    )
      .then(result => result.json())
      .then(json => {
        console.log(json);
        this.setState({refresh: !this.state.refresh});
        this.setState({message: ""});
      })
      .catch(error => console.log("error", error));
  }

  render () {
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
        >
          <View style={styles.modal}>
            <ScrollView>
              {this.props.id.messages.map((msg) => {
                if (this.props.id.person && this.props.id.person._id == msg.from) {
                  if (isURL(msg.message)){
                    return (<Image style={styles.msgFromImage} source={{uri: msg.message}} />);
                  } else {
                    return (<Text style={styles.msgFrom}>{msg.message}</Text>);
                  }
                } else {
                  if (isURL(msg.message)) {
                    return (<Image style={styles.msgImage} source={{uri: msg.message}} />);
                  } else {
                    return (<Text style={styles.msg}>{msg.message}</Text>);
                  }
                }
              })}
            </ScrollView>
            <View style={styles.form}>
              <TextField style={styles.formStyle} styleText={styles.formText} run={this.saveMessage} />
              <MessageButton run={this.sendMessage} />
            </View>
          </View>
        </Modal>
        <TouchableOpacity style={styles.showMsg} onPress={() => {this.setModal(true)}}>
          <Text style={styles.header}>{this.props.id.person.name}</Text>
        </TouchableOpacity>
      </View>
    );
  }
}

export default class Messages extends React.Component
{
  constructor(props) {
    super(props);
    this.state = {
      data : [],
      refresh: false,
    };
    this.refreshMe = this.refreshMe.bind(this);
  }

  refreshMe () {
    this.setState({refresh: !this.state.refresh});
  }

  componentDidMount() {
    fetch(`https://api.gotinder.com/updates`, {
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
      method: "POST",
      body: '{"last_activity_date": "2014-04-10T10:17:54.379Z"}',
      mode: "cors"
    })
      .then(result => result.json())
      .then(json => {
        this.setState({data: json.matches});
        console.log(this.state.data)
      });
  }

  render() {
    if (this.state.data.length <= 0 ) {
      return (<View></View>);
    } else {
      console.log("----------------------------");
      console.log(this.state.data.length);
      console.log("----------------------------");
      return (
        <View style={styles.container}>
          {this.state.data.map((mdr) => {return (
            <View style={styles.messageBox}>
              <User id={mdr} />
              <Msg id={mdr} ref={this.refreshMe} />
            </View>
          );})}
        </View>
      );
    }
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
  messageBox: {
    flexDirection: 'row',
    width: '100%',
    height: 150,
  },
  modal: {
    flex: 1,
    paddingTop: 20,
    width: '100%',
    backgroundColor: '#495057',
  },
  header: {
    fontWeight: "bold",
    fontSize: 20,
    marginLeft: 10,
  },
  showMsg: {
    width: 500,
    height: '100%',
    justifyContent: 'center',
  },
  msg: {
    paddingTop: 5,
    paddingBottom: 5,
    paddingRight: 5,
    paddingLeft: 5,
    marginTop: 5,
    marginBottom: 5,
    marginRight: 5,
    marginLeft: 5,
    textAlign: 'right',
    backgroundColor: '#c70082',
    borderRadius:10,
    borderWidth: 1,
  },
  msgFrom: {
    paddingTop: 5,
    paddingBottom: 5,
    paddingRight: 5,
    paddingLeft: 5,
    marginTop: 5,
    marginBottom: 5,
    marginRight: 5,
    marginLeft: 5,
    textAlign: 'left',
    color: 'white',
    borderRadius:10,
    borderWidth: 1,
  },
  msgFromImage: {
    width: 200,
    height: 200,
    paddingTop: 5,
    paddingBottom: 5,
    paddingRight: 5,
    paddingLeft: 5,
    marginTop: 5,
    marginBottom: 5,
    marginRight: 5,
    marginLeft: 5,
    textAlign: 'left',
    color: 'white',
    borderRadius:10,
    borderWidth: 1,
  },
  msgImage: {
    width: 200,
    height: 200,
    paddingTop: 5,
    paddingBottom: 5,
    paddingRight: 5,
    paddingLeft: 5,
    marginTop: 5,
    marginBottom: 5,
    marginRight: 5,
    marginLeft: 5,
    textAlign: 'right',
    color: 'white',
    borderRadius:10,
    borderWidth: 1,
  },
  form: {
    flexDirection: 'row',
    alignItems: 'center',
  },
  formText: {
    width: '100%',
    height: '100%',
    color: "#FFFFFF",
    borderBottomWidth: 1,
    borderColor: '#c70082',
    fontSize: 20,
  },
  formStyle: {
    width: '75%',
    height: 30,
    marginTop: 15,
    marginRight: 15,
    marginLeft: 15,
    marginBottom: 15,
  },
});
