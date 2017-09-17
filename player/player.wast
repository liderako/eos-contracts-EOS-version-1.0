(module
 (type $FUNCSIG$ijjii (func (param i64 i64 i32 i32) (result i32)))
 (type $FUNCSIG$ijji (func (param i64 i64 i32) (result i32)))
 (type $FUNCSIG$j (func (result i64)))
 (import "env" "currentCode" (func $currentCode (result i64)))
 (import "env" "remove_i64" (func $remove_i64 (param i64 i64 i32) (result i32)))
 (import "env" "store_i64" (func $store_i64 (param i64 i64 i32 i32) (result i32)))
 (table 0 anyfunc)
 (memory $0 1)
 (data (i32.const 4) " @\00\00")
 (data (i32.const 16) "player\00")
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
  (local $0 i32)
  (local $1 i32)
  (local $2 i64)
  (local $3 i64)
  (local $4 i64)
  (local $5 i64)
  (local $6 i32)
  (i32.store offset=4
   (i32.const 0)
   (tee_local $6
    (i32.sub
     (i32.load offset=4
      (i32.const 0)
     )
     (i32.const 16)
    )
   )
  )
  (set_local $3
   (i64.const 0)
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 16)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$0
   (block $label$1
    (block $label$2
     (block $label$3
      (block $label$4
       (block $label$5
        (br_if $label$5
         (i64.gt_u
          (get_local $3)
          (i64.const 5)
         )
        )
        (br_if $label$4
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 160)
         )
        )
        (br $label$3)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$2
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$1)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 234)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$0
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $5
   (call $currentCode)
  )
  (set_local $3
   (i64.const 0)
  )
  (i64.store offset=8
   (get_local $6)
   (i64.const 0)
  )
  (i64.store
   (get_local $6)
   (get_local $5)
  )
  (drop
   (call $remove_i64
    (get_local $4)
    (i64.const 632468476610478080)
    (get_local $6)
   )
  )
  (set_local $2
   (i64.const 59)
  )
  (set_local $1
   (i32.const 16)
  )
  (set_local $4
   (i64.const 0)
  )
  (loop $label$6
   (block $label$7
    (block $label$8
     (block $label$9
      (block $label$10
       (block $label$11
        (br_if $label$11
         (i64.gt_u
          (get_local $3)
          (i64.const 5)
         )
        )
        (br_if $label$10
         (i32.gt_u
          (i32.and
           (i32.add
            (tee_local $0
             (i32.load8_s
              (get_local $1)
             )
            )
            (i32.const -97)
           )
           (i32.const 255)
          )
          (i32.const 25)
         )
        )
        (set_local $0
         (i32.add
          (get_local $0)
          (i32.const 160)
         )
        )
        (br $label$9)
       )
       (set_local $5
        (i64.const 0)
       )
       (br_if $label$8
        (i64.le_u
         (get_local $3)
         (i64.const 11)
        )
       )
       (br $label$7)
      )
      (set_local $0
       (select
        (i32.add
         (get_local $0)
         (i32.const 234)
        )
        (i32.const 0)
        (i32.lt_u
         (i32.and
          (i32.add
           (get_local $0)
           (i32.const -49)
          )
          (i32.const 255)
         )
         (i32.const 5)
        )
       )
      )
     )
     (set_local $5
      (i64.shr_s
       (i64.shl
        (i64.extend_u/i32
         (get_local $0)
        )
        (i64.const 56)
       )
       (i64.const 56)
      )
     )
    )
    (set_local $5
     (i64.shl
      (i64.and
       (get_local $5)
       (i64.const 31)
      )
      (i64.and
       (get_local $2)
       (i64.const 4294967295)
      )
     )
    )
   )
   (set_local $1
    (i32.add
     (get_local $1)
     (i32.const 1)
    )
   )
   (set_local $3
    (i64.add
     (get_local $3)
     (i64.const 1)
    )
   )
   (set_local $4
    (i64.or
     (get_local $5)
     (get_local $4)
    )
   )
   (br_if $label$6
    (i64.ne
     (tee_local $2
      (i64.add
       (get_local $2)
       (i64.const -5)
      )
     )
     (i64.const -6)
    )
   )
  )
  (set_local $3
   (call $currentCode)
  )
  (i64.store offset=8
   (get_local $6)
   (i64.const 0)
  )
  (i64.store
   (get_local $6)
   (get_local $3)
  )
  (drop
   (call $store_i64
    (get_local $4)
    (i64.const 632468476610478080)
    (get_local $6)
    (i32.const 16)
   )
  )
  (i32.store offset=4
   (i32.const 0)
   (i32.add
    (get_local $6)
    (i32.const 16)
   )
  )
 )
 (func $apply (param $0 i64) (param $1 i64)
 )
)
