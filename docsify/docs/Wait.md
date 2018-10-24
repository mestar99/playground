# Wait

A module aimed at easing debugging by mocking complex flow behaviors. In short, with each DataCollection
arrival, the Wait module waits for a specified amount of time before releasing the collection to
subsequent modules.

Module Type: InStream

## Parameters

```
Name             Type                 Measurement       Description
--------         -----                ------------      ------------
Wait Time        Double               Temporal          The amount of time to process (wait) for each DataCollection
Output Interval  Double               Temporal          Output to the log at this interval of the Wait Time
```

## Ports

```
Port Name                    Required         Description
---------                    --------         -----------
data-io-stream-input-edge    Yes              Input port
data-io-stream-output-edge   Yes*             Output port

*Output ports are never required, but for this module to be of any use (any InStreamModule in fact), the output
 port should be connected to a downstream module.
```
