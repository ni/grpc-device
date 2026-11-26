# CRA Evidence Report

**Repository:** ni/grpc-device  
**Assessment Date:** 2026-11-25

---

# Requirement 1 - Dangerous Workflows

## Review

Reviewed all GitHub Actions workflows in `.github/workflows` for dangerous workflow patterns, including:

- `pull_request_target` usage
- `workflow_run` trust boundaries
- Untrusted code execution
- Secret exposure
- Excessive workflow permissions
- Unsafe use of GitHub context values
- Artifact download and execution

## Findings

No dangerous workflow patterns were identified.

Verified:

- No use of `pull_request_target`
- No unsafe execution of pull request titles, descriptions, comments, issue bodies, or branch names
- No unsafe checkout of untrusted pull request code in privileged workflows
- No unsafe artifact execution patterns identified

The `trigger_azdo_ci.yml` workflow was reviewed separately due to its use of `workflow_run` and Azure DevOps credentials. Review confirmed that only `CMakeLists.txt` is checked out using sparse checkout, the file is parsed as text, extracted values are limited to version numbers, and no checked-out content is executed.

## Remediation

No remediation required.

## Validation

Workflow review completed successfully.
