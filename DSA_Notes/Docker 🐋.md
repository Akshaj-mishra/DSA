## What is Docker?

**Docker** is an open-source platform that automates the deployment, scaling, and management of applications inside lightweight, isolated environments called **containers**.

- **Core Purpose:** Solves the "it works on my machine" problem by packaging code alongside all its dependencies, system tools, and libraries.

## Key Concepts & Terminology

- **Dockerfile:** A text document containing instructions to assemble a Docker image.

- **Docker Image:** A read-only blueprint or template used to create containers.

- **Docker Container:** A runnable instance of an image. It is an isolated application package running on the host OS kernel.

- **Docker Engine:** The underlying client-server application that builds and runs containers.

- **Docker Hub / Registry:** A repository service where images are stored and shared (e.g., public images for Node.js, Python, PostgreSQL).

- **Docker Volumes:** Persistent data storage mechanisms attached to containers so data survives container stops/deletions.

---
## Virtual machine vs docker

The core distinction between Virtual Machines and Docker containers comes down to **virtualization layer and OS sharing**: VMs virtualize physical hardware, while Docker containers virtualize the operating system kernel.

![Architectural comparison between VMs and Docker containers, AI generated](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcT-1DmIh7jizaYFvnEk_A_aDBxrJok0eCGQQQxB_GIfaVQx7yEI7pixmi0&s=10)

## Architecture Breakdown

### Virtual Machines (Hardware Virtualization)

- **Hypervisor:** Sits directly on top of host hardware or the host OS (e.g., VMware, VirtualBox, Hyper-V).

- **Guest OS:** Every individual VM requires a complete, standalone operating system (Linux, Windows, etc.) including its own kernel, system binaries, and drivers.

- **Footprint:** Massive size (several GBs per VM) and higher CPU/RAM overhead because each instance runs a full OS.

- uses application layer of its own and also brings its own os kernel 

### Docker Containers (OS-Level Virtualization)

- **Docker Engine:** Sits on top of the host operating system.

- **Shared Kernel:** Containers share the host system's OS kernel directly. They package only application code, dependencies, and necessary runtime libraries.

- **Footprint:** Extremely lightweight (tens to hundreds of MBs) with minimal CPU and RAM overhead.

- only has os application layer

## Feature Comparison

- **Architecture:** VMs use a Hypervisor with a dedicated Guest OS per instance; Docker uses the Docker Engine sharing the Host OS kernel.

- **Startup Time:** VMs take minutes to boot up an entire OS; Docker containers start up in seconds or milliseconds.

- **Resource Consumption:** VMs require static allocation of CPU, RAM, and disk space; Docker containers dynamically consume only what the app requires.

- **Storage Footprint:** VMs consume tens of GBs per image; Docker images are lightweight, typically ranging from 50 MB to 1 GB.

- **Isolation & Security:** VMs provide strict hardware-level isolation (stronger boundary); Docker provides process-level isolation via Linux namespaces/cgroups (slightly lighter boundary).

- **Portability:** VMs can be slow to export/import due to heavy image sizes; Docker containers build fast, run identically anywhere, and push easily to registries.
## When to Use Which

**Choose Docker Containers when:**

- Building cloud-native microservices or web applications.

- Setting up fast CI/CD pipelines and automated deployments.

- Scaling instances up or down instantly.

- Ensuring identical runtime environments across local development, testing, and production.

**Choose Virtual Machines when:**

- Running applications that require different OS kernels (e.g., running Windows Server on a Linux host).
- Strong, hardware-isolated security environments are strictly required (multitenant compliance).
- Running legacy monolithic apps that rely heavily on underlying OS configurations.

![[Pasted image 20261002125257.png]]

---
## Docker Images vs. Docker Containers

### Docker Image

- **Executable Application Artifact:** Serves as a packaged, read-only template or blueprint.
- **Components Included:** Contains the **Application**, **Any services needed**, and the underlying **OS Layer**.
- **Full Configuration:** Includes the application source code alongside the complete environment configuration.
- **Customization:** Configured by adding environment variables, creating directories, adding files, etc.

### Docker Container

- **Live Execution:** It is the running instance that actually starts and runs the application.
- **Relationship:** Created directly from a Docker Image—the image defines what goes inside, while the container executes it.


![[Pasted image 20261002125928.png]]

---
## Docker Registries

- **Storage & Distribution System:** A centralized system used to store and distribute Docker images.
- **Discovery & Sharing:** Allows users to easily find existing images and share their own Docker images with others.
- **Docker Hub:** Docker hosts one of the largest public registries, known as **Docker Hub**.

### Key Commands Related to Registries

- **`docker login`** – Authenticate with a Docker registry (e.g., Docker Hub).

- **`docker pull <image_name>`** – Download an image from a registry to your local system.

- **`docker push <username>/<repository>:<tag>`** – Upload a locally built image to a registry.

---

## Docker Image Versioning

Image versioning relies on **tags** and **digests** to identify specific builds, ensuring consistency, repeatability, and safety across development and production environments.

  

## 1. How Tagging Works

- **Image Reference Format:**  `registry/repository:tag`

- **Default Tag:** If no tag is provided, Docker automatically applies `:latest`.

- **Tags are Mutable:** Tags are human-readable labels that point to a specific image hash. Pushing a new build with an existing tag updates that tag to point to the new image digest.


Bash

```
# Tagging during build
docker build -t myapp:1.0.0 .

# Tagging an existing image
docker tag myapp:1.0.0 myregistry.com/team/myapp:1.0.0
```

## 2. Common Versioning Strategies

### A. Semantic Versioning (SemVer)

Best for public applications, microservices, and libraries.

  

- Format: `MAJOR.MINOR.PATCH` (e.g., `1.2.3`).

- **Multi-Tagging Approach:** Often, a single build receives multiple tags to allow users to pin to different risk tolerances:
      
    - `myapp:1.2.3` (Exact patch - immutable intent)
    
    - `myapp:1.2` (Points to latest `1.2.x` patch)
    
    - `myapp:1` (Points to latest `1.x.x` minor release)
    
    - `myapp:latest` (Points to the newest overall build)

### B. Git Commit SHA Tagging

Best for continuous integration / deployment pipelines.

  

- Format: `myapp:sha-a1b2c3d` or `myapp:<build_number>`.

- **Benefit:** Provides a direct link between a running container and the exact source code revision.

### C. Immutable Tags & Environment Tagging

- Production registries can be configured to enforce **Immutable Tags** so tags cannot be overwritten.

- Promotion pipelines move images across stages using environmental tags (e.g., `dev` $\rightarrow$ `staging` $\rightarrow$ `prod`).
  

## 3. Tags vs. Digests

|**Metric**|**Docker Tag (:1.0.0)**|**SHA Digest (@sha256:...)**|
|---|---|---|
|**Type**|Human-readable pointer|Cryptographic content hash|
|**Mutability**|Mutable (can be overwritten)|Immutable (never changes)|
|**Use Case**|Human operations, environment promotion|Production deployments requiring 100% deterministic builds|

Dockerfile

```
# Pinning by tag (readable, but tag could be updated)
FROM node:20.11-alpine

# Pinning by digest (guaranteed immutable)
FROM node@sha256:abc123def4567890...
```

## 4. Key Best Practices

- **Avoid `:latest` in Production:** The `:latest` tag does not imply the "highest version"; it merely points to the last untagged push, leading to non-deterministic deployments.

- **Pin Base Images:** Explicitly state the OS and runtime versions in `Dockerfile` base images (e.g., `python:3.11-slim`).
   
- **Add OCI Metadata Labels:** Store versioning metadata directly inside image layers using `LABEL` instructions.

Dockerfile

```
LABEL org.opencontainers.image.version="1.2.3"
LABEL org.opencontainers.image.revision="a1b2c3d"
```

---

###  `docker pull` and `docker run`
## High-Level Lifecycle Flow

```
[ Registry ]
     │
     │  (docker pull)
     ▼
[ Local Image Cache ]
     │
     │  (docker run)
     ▼
[ Writable Layer + Process Namespace (Container) ]
```

## 1. Deep Dive: `docker pull`

The `docker pull` command is responsible solely for downloading images (or sets of layers) from a remote registry (like Docker Hub, AWS ECR, or GitHub Packages) onto the local Docker host.

### Execution Step-by-Step

1. **Client Request:** The Docker CLI sends an HTTP REST API request to the Docker Daemon (`dockerd`) requesting a target image tag (e.g., `nginx:1.25`).

2. **Registry Manifest Lookup:** `dockerd` contacts the target registry and requests the image manifest. The manifest contains a JSON file describing the configuration, architecture (e.g., `amd64`, `arm64`), and cryptographic digests (`sha256`) of each layer in the image.

3. **Layer Diff & Deduplication:** `dockerd` checks its local image cache against the SHA256 hashes listed in the manifest:
    
    - **If a layer exists locally:** The layer download is skipped.
    
    - **If missing:** The layer blob (`tar.gz`) is downloaded concurrently over HTTP/2.
    
4. **Unpacking & Assembly:** Each downloaded layer is decompressed and placed in the host’s graph storage driver system (e.g., `overlay2`). Layers are stacked sequentially as read-only filesystem snapshots.

5. **Registration:** `dockerd` records the image ID and manifest locally. **No processes are started, and no memory or CPU resources are allocated.**


### Common Flags & Variations

- `docker pull ubuntu:22.04`: Fetches the specified version.

- `docker pull --all-tags ubuntu` (`-a`): Downloads all tagged images within the repository.

- `docker pull --platform linux/amd64 node:20`: Explicitly pulls a specific architecture variant on multi-architecture systems.


## 2. Deep Dive: `docker run`

`docker run` is a multi-step operation that provisions and executes an isolated container environment from an image. Behind the scenes, `docker run` combines `docker create` and `docker start` into a single atomic action.

### Execution Step-by-Step

1. **Image Existence Check:**
    
    - `dockerd` verifies if the requested image exists in the local cache.
    
    - **Implicit Pull:** If missing (and default `--pull missing` is set), `dockerd` automatically triggers a `docker pull` operation before continuing.
    
2. **Writable Container Layer Addition:**
    
    - Using the storage driver (e.g., `overlay2`), `dockerd` stacks a thin **Read-Write container layer** on top of the read-only image layers.
    
    - Any files modified, created, or deleted during runtime are isolated to this top layer via Copy-on-Write (CoW).
    
3. **Low-Level Container Provisioning (`containerd` & `runc`):**
    
    - `dockerd` passes the run parameters to `containerd` via gRPC.
    
    - `containerd` invokes `runc` (the OCI runtime standard) to interface directly with the Linux kernel.
    
4. **Kernel Isolation Setup:**
    
    - **Namespaces:** Creates dedicated isolated spaces for PID (processes), NET (networking), MNT (mounts), IPC (inter-process communication), and UTS (hostnames).
    
    - **Control Groups (cgroups):** Enforces hardware limits (RAM, CPU share, I/O bandwidth).
    
5. **Network Attachment & Port Mapping:**
    
    - Attaches a virtual network interface (e.g., `veth`) to the container and binds it to the Docker bridge network (`docker0`).
    
    - If `-p` is passed, `iptables` rules or `docker-proxy` instances map host ports to container ports.
    
6. **Process Execution:**
    
    - Executes the entrypoint/command defined in the Dockerfile or CLI (PID 1).

## Comparative Breakdown

- **Primary Function:** `docker pull` fetches/syncs read-only image layers from a registry; `docker run` provisions execution environments, mounts writable layers, and starts isolated processes.

- **Execution Overhead:** `docker pull` relies heavily on network bandwith and disk I/O; `docker run` consumes kernel memory, CPU time, and runtime system resources.

- **System Impact:** `docker pull` alters local storage disk usage; `docker run` creates active host processes, network sockets, and dynamic cgroup allocations.

- **Re-execution Behavior:** `docker pull` updates local images if remote manifests change; `docker run` reuses existing local images by default without pulling updates unless configured.

## Controlling Pull Policy during `docker run`

The `--pull` flag modifies how `docker run` handles local image lookups:

- `docker run --pull missing myapp` **(Default):** Only pulls if the image is missing locally.

- `docker run --pull always myapp`: Always contacts the registry to check for/download updated image layers before creating the container.

- `docker run --pull never myapp`: Forces execution strictly from local cache; throws an error if missing.

## When to Use Which Separately

- **Use `docker pull` explicitly when:**
    
    - Pre-warming CI/CD runner nodes to speed up pipeline steps.
    
    - Ensuring zero-downtime deployments by downloading heavy images _before_ stopping old running containers.
    
    - Updating base image layers during scheduled security patching workflows.
    
- **Use `docker run` directly when:**
    
    - Spin-ups require automated, stateless execution (e.g., automated test runners).
    
    - Working interactively in local development workflows (`docker run -it --rm ubuntu bash`).

![[Pasted image 20261002195621.png]]

---

