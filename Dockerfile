FROM ubuntu:18.04
LABEL description="gcc for H8"
# build-essential(gcc etc) install
ENV USER user
ENV HOME /home/${USER}
ENV SHELL /bin/bash
RUN useradd -m ${USER} # 一般ユーザーアカウントを追加
RUN gpasswd -a ${USER} sudo # 一般ユーザーにsudo権限を付与
RUN echo "${USER}:user_pass" | chpasswd # 一般ユーザーのパスワード設定
RUN sed -i.bak "s#${HOME}:#${HOME}:${SHELL}#" /etc/passwd  # ログインシェルを指定（アカウント情報の作成）

RUN apt-get update \
    && apt-get install -y \
        autogen \
        build-essential \
        libgmp-dev \
        libmpfr-dev \
        libmpc-dev \
        wget \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# download and build binutils for h8300
WORKDIR /home/h8300-tools
RUN wget https://ftp.gnu.org/gnu/binutils/binutils-2.30.tar.gz \
    && tar zxvf binutils-2.30.tar.gz \
    && rm binutils-2.30.tar.gz
WORKDIR /home/h8300-tools/binutils-build
RUN ./../binutils-2.30/configure \
        --prefix=/usr/local \
        --target=h8300-elf \
    && make \
    && make install

# download and build gcc for h8300
WORKDIR /home/h8300-tools/
RUN wget https://ftp.gnu.org/gnu/gcc/gcc-7.3.0/gcc-7.3.0.tar.gz \
    && tar zxvf gcc-7.3.0.tar.gz \
    && rm gcc-7.3.0.tar.gz
WORKDIR /home/h8300-tools/gcc-build
RUN ./../gcc-7.3.0/configure \
        --disable-libstdcxx-pch \
        --disable-libssp \
        --disable-nls \
        --disable-shared \
        --disable-threads \
        --enable-gold \
        --enable-languages=c \
        --enable-lto \
        --enable-sjlj-exceptions \
        --prefix=/usr/local \
        --target=h8300-elf \
        --with-gmp=/usr/local \
        --with-mpfr=/usr/local \
        --with-mpc=/usr/local \
        --disable-bootstrap \
    && make \
    && make check \
    && make install

WORKDIR /home
# RUN rm -rf /home/h8300-tools
# ENV PATH $PATH:/usr/local/h8300-elf/bin
