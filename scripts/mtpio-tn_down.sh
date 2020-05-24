#!/bin/bash
#
# mtpio-tn_down.sh is used by the mtpio-tn_bounce.sh and mtpio-tn_roll.sh scripts.
# It is intended to terminate specific MTP.IO daemon processes.
#


if [ "$PWD" != "$MTPIO_HOME" ]; then
    echo $0 must only be run from $MTPIO_HOME
    exit -1
fi

prog=nodmtp

DD=var/lib/node_$MTPIO_NODE
runtest=`cat $DD/$prog.pid`
echo runtest = $runtest
running=`ps -e | grep $runtest | grep -cv grep `

if [ $running -ne 0 ]; then
    echo killing $prog

    kill -15 $runtest

    for (( a = 1;11-$a; a = $(($a + 1)) )); do
        echo waiting for safe termination, pass $a
        sleep 2
        running=`ps -e | grep $runtest | grep -cv grep`
        echo running = $running
        if [ $running -eq 0 ]; then
            break;
        fi
    done
fi

if [ $running -ne 0 ]; then
    echo killing $prog with SIGTERM failed, trying with SIGKILL
    pkill -9 $runtest
fi
