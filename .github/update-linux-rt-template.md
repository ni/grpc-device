---
title: Update Linux RT Feed to point to new release {{ env.NEW_RELEASE }}
---

Linux RT needs to be updated to point to the new grpc-device release.

Update the following lines in `recipes-ni/ni-grpc-device/ni-grpc-device_git.bb` in [ni/meta-nilrt](https://github.com/ni/meta-nilrt)
- PV = "{{ env.NEW_RELEASE }}"
- SRCBRANCH = "{{ env.GITHUB_BRANCH }}"
- SRCREV_grpc-device = "{{ env.GITHUB_SHA }}"
