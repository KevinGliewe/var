# Ubuntu 22 gcc 12 clang-15 (only format)
FROM mcr.microsoft.com/devcontainers/base:ubuntu-22.04

USER root

# Set bash to default shell
RUN echo '#! /bin/sh' > /usr/bin/mesg && chmod 755 /usr/bin/mesg
SHELL ["/bin/bash", "--login", "-c"]

# Dependencies:
RUN export DEBIAN_FRONTEND=noninteractive; \
    apt-get -qq update && apt-get -qq install --no-install-recommends \
    curl \
    g++-12 \
    gcc-12 \
    gdb \
    git \
    ninja-build \
    pkg-config \
    tar \
    unzip \
    zip \
    p7zip-full \
    && apt -qq autoremove \
    && apt -qq clean \
    && rm -rf /var/lib/apt/lists/*

# Install CMake
ARG CMAKE_VERSION="3.27.6"
RUN declare -A archs=( ["amd64"]="x86_64" ["arm64"]="aarch64" ); \
    architecture=$(dpkg --print-architecture); \
    echo "Detected arch: $architecture => ${archs[$architecture]}"; \
    [[ "${archs[$architecture]}" != "" ]] \
    && mkdir -p /opt/cmake \
    && CMAKE_BINARY_NAME="cmake-$CMAKE_VERSION-linux-${archs[$architecture]}.sh" \
    && TMP_DIR=$(mktemp -d -t cmake-XXXXXXXXXX) \
    && pushd "$TMP_DIR" \
    && curl -sSL "https://github.com/Kitware/CMake/releases/download/v$CMAKE_VERSION/$CMAKE_BINARY_NAME" -O \
    && sh "$TMP_DIR/$CMAKE_BINARY_NAME" --prefix=/opt/cmake --skip-license \
    && popd \
    && rm -rf "$TMP_DIR" \
    && ln -s -t /usr/local/bin /opt/cmake/bin/cmake /opt/cmake/bin/ccmake /opt/cmake/bin/ctest /opt/cmake/bin/cpack

# Install vcpkg for user vscode
ENV VCPKG_ROOT=/usr/local/vcpkg \
    VCPKG_NO_CI=1
RUN mkdir -p "$VCPKG_ROOT" \
    && chown vscode:vscode "$VCPKG_ROOT" \
    && su vscode -c "git clone -c core.eol=lf -c core.autocrlf=false -c fsck.zeroPaddedFilemode=ignore -c fetch.fsck.zeroPaddedFilemode=ignore -c receive.fsck.zeroPaddedFilemode=ignore https://github.com/microsoft/vcpkg $VCPKG_ROOT" \
    && VCPKG_DOWNLOADS="$HOME/.cache/vcpkg/downloads" \
    && sh "$VCPKG_ROOT/bootstrap-vcpkg.sh" \
    && rm -rf "$VCPKG_DOWNLOADS" \
    && ln -s "$VCPKG_ROOT/vcpkg" "/usr/local/bin/vcpkg" \
    && echo 'export VCPKG_DOWNLOADS="$HOME/.cache/vcpkg/downloads"' >> ~vscode/.bash_profile

USER vscode