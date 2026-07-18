# Security Policy

## Supported Versions

The latest version of this project receives security updates and bug fixes.

| Version | Supported |
|:---------|:---------:|
| Latest Release | ✅ |
| Older Releases | ❌ |

---

## Reporting a Security Vulnerability

If you discover a security vulnerability, please **do not** create a public GitHub issue.

Instead, report the issue responsibly so that it can be investigated and resolved before public disclosure.

When reporting a vulnerability, please include:

- Description of the issue
- Steps to reproduce
- Affected firmware version
- Hardware configuration
- Impact assessment
- Suggested mitigation (if available)

---

## Response Process

After receiving a security report, the following process will be followed:

1. Acknowledge receipt of the report.
2. Investigate the reported issue.
3. Validate the vulnerability.
4. Develop and test a fix.
5. Release a patched version.
6. Publicly disclose the issue after the fix becomes available.

---

## Scope

This security policy applies to:

- STM32 Blue Pill Firmware
- ESP32 Firmware
- UART Communication
- ThingSpeak Integration
- Telegram Bot Integration
- Documentation included in this repository

---

## Security Recommendations

For users deploying this project:

- Never expose your Wi-Fi credentials publicly.
- Keep your ThingSpeak API Key private.
- Never share your Telegram Bot Token.
- Protect your Telegram Chat ID when possible.
- Use strong passwords for all cloud services.
- Keep the ESP32 and STM32 board packages updated.
- Use the latest Arduino IDE version.
- Regularly update third-party libraries.

---

## Third-Party Services

This project relies on the following external services:

- ThingSpeak
- Telegram Bot API
- Arduino Framework

Please follow the security best practices recommended by these platforms.

---

## Disclaimer

This project is provided for educational, research, and development purposes.

Although reasonable effort has been made to develop reliable firmware, users are responsible for validating the system before deploying it in production or safety-critical environments.

---

## Contact

For responsible security disclosure or questions related to this project, please use the GitHub repository's issue tracker or contact the repository maintainer.

**Maintainer:** ShivsFoundry

Thank you for helping keep this project secure.
