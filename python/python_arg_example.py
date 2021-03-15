#!/usr/bin/env python
 # Command-line options
import argparse
import sys

if __name__ == '__main__':
    #parser = argparse.ArgumentParser()
    parser = argparse.ArgumentParser(prog=sys.argv[0], add_help=True, usage='%(prog)s [options]',
            description="EXAScaler/SFA log collection and upload tools",
            epilog="All arguments are mutually exclusive i.e. can not be used combined")
    parser.add_argument("-u", "--upload", dest="infile",
                        action='store', required=False,
                        help="upload collected log bundle.")
    parser.add_argument("-s", "--sfa", dest="sfa_destination",
                        action='store', required=False,
                        help="collect sfa logs to location.")
    parser.add_argument("-e", "--exascaler", dest="exa_destination",
                        action='store', required=False,
                        help="collect sfa logs to location.")
    parse_args = parser.parse_args()
    args = parse_args
    print("infile:", args.infile)
    print("dest1:", args.sfa_destination)
    print("dest2:", args.exa_destination)
    parser.print_help()
