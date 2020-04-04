FROM ubuntu:18.04

ENV UBUNTU_FRONTEND=noninteractive

ARG USERNAME=goodboyuser
ARG USER_UID=1000
ARG USER_GID=${USER_UID}

RUN apt-get update \
    # install packages
    && apt-get install -y apt-utils dialog \
        # git
        ca-certificates iproute2 procps lsb-release git \
        #
        # C++ tools
        build-essential cmake cppcheck valgrind g++ \
        #
        # development libraries
        libsdl2-dev \
        #
        # add sudo support for the non-root user
        sudo \
    #
    #create a non-root user
    && groupadd --gid ${USER_GID} ${USERNAME} \
    && useradd -s /bin/bash --uid ${USER_UID} --gid ${USER_GID} -m ${USERNAME} \
    && echo ${USERNAME} ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/${USERNAME} \
    && chmod 0440 /etc/sudoers.d/${USERNAME} \
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
