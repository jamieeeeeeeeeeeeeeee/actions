FROM ubuntu:20.04

# Copy build script
COPY build.sh /tmp/build.sh
RUN chmod +x /tmp/build.sh

# Run build script
RUN /tmp/build.sh

# Clean up
RUN apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Check if non-ascii-spotter exists in bin
RUN test -f /usr/local/bin/non-ascii-spotter

# If it does, set it as the entrypoint
ENTRYPOINT ["/usr/local/bin/non-ascii-spotter"]