(module
 (type $FUNCSIG$ijjii (func (param i64 i64 i32 i32) (result i32)))
 (type $FUNCSIG$ijji (func (param i64 i64 i32) (result i32)))
 (type $FUNCSIG$j (func (result i64)))
 (import "env" "currentCode" (func $currentCode (result i64)))
 (import "env" "remove_i64" (func $remove_i64 (param i64 i64 i32) (result i32)))
 (import "env" "store_i64" (func $store_i64 (param i64 i64 i32 i32) (result i32)))
 (table 0 anyfunc)
 (memory $0 1)
 (data (i32.const 4) "\10@\00\00")
 (export "memory" (memory $0))
 (export "_ZN6player5StoreEyRKNS_7AccountE" (func $_ZN6player5StoreEyRKNS_7AccountE))
 (export "_ZN6player6RemoveEyRKNS_7AccountE" (func $_ZN6player6RemoveEyRKNS_7AccountE))
 (export "init" (func $init))
 (export "apply" (func $apply))
 (func $_ZN6player5StoreEyRKNS_7AccountE (param $0 i64) (param $1 i32)
  (drop
   (call $store_i64
    (get_local $0)
    (i64.const 632468476610478080)
    (get_local $1)
    (i32.const 16)
   )
  )
 )
 (func $_ZN6player6RemoveEyRKNS_7AccountE (param $0 i64) (param $1 i32)
  (drop
   (call $remove_i64
    (get_local $0)
    (i64.const 632468476610478080)
    (get_local $1)
   )
  )
 )
 (func $init
  (local $0 i64)
  (local $1 i64)
  (local $2 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $2
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (set_local $0
   (call $currentCode)
  )
  (set_local $1
   (call $currentCode)
  )
  (i64.store offset=8
   (get_local $2)
   (i64.const 0)
  )
  (i64.store
   (get_local $2)
   (get_local $1)
  )
  (drop
   (call $remove_i64
    (get_local $0)
    (i64.const 632468476610478080)
    (get_local $2)
   )
  )
  (set_local $1
   (call $currentCode)
  )
  (i64.store offset=8
   (get_local $2)
   (i64.const 0)
  )
  (i64.store
   (get_local $2)
   (get_local $1)
  )
  (drop
   (call $store_i64
    (get_local $0)
    (i64.const 632468476610478080)
    (get_local $2)
    (i32.const 16)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $2)
    (i32.const 16)
   )
  )
 )
 (func $apply (param $0 i64) (param $1 i64)
 )
)
