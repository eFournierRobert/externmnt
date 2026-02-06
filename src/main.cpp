#include <CLI/CLI.hpp>
#include "drive/driveManager.h"

void initCifsSubCom(CLI::App* subcom, bool* registerFlag) {
    subcom->add_flag("-r, --register", *registerFlag, "Register a new CIFS drive");
}

int main(int argc, char* argv[]) {
    CLI::App app{"A small program that mounts network drives", "externmnt"};
    argv = app.ensure_utf8(argv);

    CLI::App* cifsSubcom = app.add_subcommand("cifs", "Manage CIFS drives");
    bool registerCifsFlag = false;
    initCifsSubCom(cifsSubcom, &registerCifsFlag);

    CLI11_PARSE(app, argc, argv);

    DriveManager driveManager {};

    if (registerCifsFlag) {
        driveManager.addNewCifsDrive();
    }

    return 0;
}
