#include <CLI/CLI.hpp>
#include "drive/driveManager.h"

int main(int argc, char* argv[]) {
    CLI::App app{"A small program that mounts network drives", "externmnt"};
    argv = app.ensure_utf8(argv);

    bool listDrives {false};
    app.add_flag("-l, --list", listDrives, "List all the drives");

    bool mountAllDrives {false};
    app.add_flag("--mount-all", mountAllDrives, "Mount all drives");

    CLI11_PARSE(app, argc, argv);

    DriveManager driveManager {};

    if (listDrives) {
        std::cout << driveManager.toString() << std::endl;
    }

    if (mountAllDrives) {
        driveManager.mountAllDrives();
    }

    return 0;
}
