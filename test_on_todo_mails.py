#!/usr/bin/env python3
import argparse
import shutil
import subprocess
import sys
from pathlib import Path

SESSION = Path(__file__).resolve().parent
SITE_REPO = SESSION

EMLS_TO_DOMAIN = SESSION / "eml_to_domain" / "emls_to_domain.py"
DOMAIN_TO_DOMAIN = SESSION / "domain_to_domain" / "domain_to_domain.py"
UPDATE_DOMAIN = SESSION / "update_domain" / "update_domain.py"
TO_SITE = SESSION / "to_site" / "to_site.py"
PICK = SESSION / "_pick.md"

def run(*args, **kwargs) -> None:
    print(f"\n$ {' '.join(str(a) for a in args)}", flush=True)
    subprocess.run([sys.executable, *map(str, args)], check=True, **kwargs)


def main() -> None:

    parser = argparse.ArgumentParser()
    parser.add_argument("eml_dir", type=Path, help="folder with eml-files to parse")
    parser.add_argument("--ignore", type=Path, help="file with entries to ignore (same format as domain index.md to allow for cut-and-paste)")

    args = parser.parse_args()

    EML_DIR = args.eml_dir

    if not EML_DIR or not EML_DIR.is_dir():
        sys.exit(f"Not a directory: {EML_DIR}")

    if not args.ignore:
        sys.exit(f"Missing --ignore argument")
    
    if not args.ignore.is_file():
        sys.exit(f"Provided --ignore is not a file: {args.ignore}")

    IGNORE = args.ignore

    # eml-files to domain '_mail'
    run(EMLS_TO_DOMAIN, EML_DIR, SITE_REPO, "--domain", "_mail")

    if not (SITE_REPO / "_chime").is_dir():
        # Fresh target domain '_chime'
        run(DOMAIN_TO_DOMAIN, "init", SITE_REPO, "_mail", "_chime")

    with PICK.open("w", encoding="utf-8") as pick:
        run(DOMAIN_TO_DOMAIN, "diff", SITE_REPO, "_mail", "_chime", "--ignore", IGNORE, stdout=pick)
    if PICK.read_text(encoding="utf-8").strip():
        run(DOMAIN_TO_DOMAIN, "add", SITE_REPO, "_mail", "_chime", "--pick", PICK)
    else:
        print("Nothing new to add to chime.")

    run(UPDATE_DOMAIN, "intralink", SITE_REPO, "_chime")

    run(TO_SITE, SITE_REPO)  # serves the site until you press Ctrl-C

if __name__ == "__main__":
    try:
        main()
    except subprocess.CalledProcessError as e:
        sys.exit(e.returncode)
    except KeyboardInterrupt:
        pass
