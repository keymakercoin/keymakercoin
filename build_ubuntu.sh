#Clone Repo
#git clone https://github.com/keymakercoin/keymakercoin.git
cd keymakercoin

 
sudo apt-get update -y
sudo apt-get install git build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils python3 -y
sudo apt-get install  ccache libboost-dev libboost-system-dev libboost-filesystem-dev libboost-chrono-dev libboost-program-options-dev libboost-test-dev libboost-thread-dev -y
sudo apt-get install libboost-all-dev -y


#BerkleyDB for wallet support only
sudo apt-get install software-properties-common -y
sudo echo | sudo add-apt-repository ppa:bitcoin/bitcoin
sudo apt-get update
sudo apt-get install libdb4.8-dev libdb4.8++-dev libevent-dev libzmq3-dev -y


#upnp
sudo apt-get install libminiupnpc-dev -y




#ZMQ
sudo apt-get install libzmq3-dev -y


# To compile wallet
./contrib/install_db4.sh `pwd`

#QT

sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler -y


./autogen.sh
./configure
make
make install
