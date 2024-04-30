FROM ubuntu:20.04

# Set the non-interactive frontend for Debian-based package installations
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages
RUN apt-get update
RUN apt-get install -y gcc build-essential --no-install-recommends

# Copy build script source file
COPY action.c /tmp/action.c

# Compile the C program
RUN gcc /tmp/action.c -o /usr/local/bin/non-ascii-spotter

# Clean up temporary files
RUN apt-get clean
RUN rm -rf /tmp/* /var/lib/apt/lists/*

# Check if non-ascii-spotter exists in the expected location
RUN if [ ! -f /usr/local/bin/non-ascii-spotter ]; then \
        echo "non-ascii-spotter not found"; \
        exit 1; \
    fi

# Set the entrypoint to non-ascii-spotter
ENTRYPOINT ["/usr/local/bin/non-ascii-spotter"]