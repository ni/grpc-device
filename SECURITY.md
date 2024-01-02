# Security Policy

## Supported Versions

NI supports the latest release of grpc-device with security updates. 

## Reporting a Vulnerability

NI is committed to resolving major security vulnerabilities discovered in grpc-device.

The development team regularly monitors the NIST National Vulnerability Database for published vulnerabilities, and uses that information to audit the grpc-device software. When a vulnerability is discovered, the team evaluates its impact to our products and our customers’ supported workflows. The team then decides to address major vulnerabilities depending on its impact to supported workflows. 

Vulnerabilities which the team assesses as being high-severity will be patched or otherwise fixed in the following release of the software. Critical-severity vulnerabilities may have their fixes applied to the current release, as well. To ensure that your deployments remain free of vulnerabilities, it is best to schedule regular upgrades of your deployments’ firmware and base system images.

We encourage you to report security vulnerabilities to us privately so that we can follow a coordinated disclosure process, allowing us time to thoroughly investigate security issues and publicly disclose them when appropriate.

To report security issues in our products or on ni.com, email security@ni.com with sufficient details about how to reproduce the issue. You may use the [NI PGP key](https://www.ni.com/en/support/security/pgp.html) to encrypt any sensitive communications you send to us. When you notify us of a potential security issue, our remediation process includes acknowledging receipt and coordinating any necessary response activities with you.

If you are interested in reporting a security issue in an NI product other than grpc-device, reference the company security page [here](https://ni.com/security).

## Requesting CVE Exposure information
Vulnerabilities in community software packages are frequently fixed by patching the source code, without changing the package’s final version number. Because of this, vulnerability scanners sometimes erroneously flag a package as being vulnerable to exploits which have already been patched. To request a disposition about whether your deployed version of grpc-device is exposed to a vulnerability, send an email to product-security@ni.com with information about your deployed system and the discrete set of interesting CVEs.
