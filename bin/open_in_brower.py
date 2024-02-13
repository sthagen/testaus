#! /usr/bin/env python
"""Call open or start on the raguments received depending on platform."""
import platform
import subprocess
import sys


def main(argv: list[str]) -> int:
    """Call shell to application gateway with the received arguments."""
    default_gateway = 'open'
    gateway_of = {
        'Darwin': default_gateway,
        'Linux': 'xdg-open',
        'Windows': 'start',
    }
    gateway = gateway_of.get(platform.system(), default_gateway)

    try:
        retcode = subprocess.call(' '.join([gateway, *argv]), shell=True)
        if retcode < 0:
            print("Child was terminated by signal", -retcode, file=sys.stderr)
        else:
            print("Child returned", retcode, file=sys.stderr)
    except OSError as e:
            print("Execution failed:", e, file=sys.stderr)

    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
