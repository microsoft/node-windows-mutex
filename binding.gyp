{
  "targets": [
    {
      "target_name": "CreateMutex",
      "sources": [ "src/main.cc" ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}