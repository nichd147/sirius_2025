docker pull ubuntu
docker run -it -p 5555:5555 --name ubuntu-painlessMeshBoost ubuntu sh

apt update
apt install -y build-essential
apt install -y git cmake
apt install -y libboost-system-dev libboost-thread-dev libboost-regex-dev libboost-program-options-dev libboost-chrono-dev libboost-date-time-dev libboost-atomic-dev libboost-filesystem-dev
cd /home/ubuntu
git clone --recurse-submodules https://gitlab.com/painlessMesh/painlessmeshboost.git

cd painlessmeshboost
cmake .
make
make install
painlessMeshBoost

============


https://gitlab.com/painlessMesh/painlessMesh
https://gitlab.com/painlessMesh/painlessMesh/-/wikis/bridge-between-mesh-and-another-network
https://gitlab.com/painlessMesh/painlessmeshboost/-/tree/master/src?ref_type=heads
https://gitlab.com/painlessMesh/painlessmeshboost