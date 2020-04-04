FROM ubuntu:18.04

ENV UBUNTU_FRONTEND=noninteractive

RUN apt-get update \
    # install packages
    && apt-get install -y --no-install-recommends apt-utils dialog \
        # git
        ca-certificates iproute2 procps lsb-release git \
        #
        # C++ tools
        build-essential cmake cppcheck valgrind g++ \
        #
        # development libraries
        libsdl2-dev \
    #
    # create directory for project
    && mkdir -p /home/goodboy \
    && cd /home/goodboy \
    #
    # clean up
    && apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

ENV UBUNTU_FRONTEND=dialog
