{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  # nativeBuildInputs is usually where you put tools you need in the shell
  nativeBuildInputs = with pkgs; [
    python3
    platformio
    minicom
  ];

  shellHook = ''
    echo "  DOnt forget for udev and dialout"
  '';
}
