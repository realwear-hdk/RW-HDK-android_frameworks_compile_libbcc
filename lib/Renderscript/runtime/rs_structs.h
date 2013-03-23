#ifndef _RS_STRUCTS_H_
#define _RS_STRUCTS_H_

/*****************************************************************************
 * CAUTION
 *
 * The following structure layout provides a more efficient way to access
 * internal members of the C++ class Allocation owned by librs. Unfortunately,
 * since this class has virtual members, we can't simply use offsetof() or any
 * other compiler trickery to dynamically get the appropriate values at
 * build-time. This layout may need to be updated whenever
 * frameworks/base/libs/rs/rsAllocation.h is modified.
 *
 * Having the layout information available in this file allows us to
 * accelerate functionality like rsAllocationGetDimX(). Without this
 * information, we would not be able to inline the bitcode, thus resulting in
 * potential runtime performance penalties for tight loops operating on
 * allocations.
 *
 *****************************************************************************/
typedef enum {
    RS_ALLOCATION_MIPMAP_NONE = 0,
    RS_ALLOCATION_MIPMAP_FULL = 1,
    RS_ALLOCATION_MIPMAP_ON_SYNC_TO_TEXTURE = 2
} rs_allocation_mipmap_control;

typedef struct Allocation {
    char __pad[28];
    struct {
        void * drv;
        struct {
            const void *type;
            uint32_t usageFlags;
            rs_allocation_mipmap_control mipmapControl;
            uint32_t yuv;
            uint32_t elementSizeBytes;
            bool hasMipmaps;
            bool hasFaces;
            bool hasReferences;
            void * usrPtr;
            int32_t surfaceTextureID;
            void * wndSurface;
            void * surfaceTexture;
        } state;

        struct DrvState {
            struct LodState {
                void * mallocPtr;
                size_t stride;
                uint32_t dimX;
                uint32_t dimY;
                uint32_t dimZ;
            } lod[16/*android::renderscript::Allocation::MAX_LOD*/];
            size_t faceOffset;
            uint32_t lodCount;
            uint32_t faceCount;
        } drvState;
    } mHal;
} Allocation_t;

/*****************************************************************************
 * CAUTION
 *
 * The following structure layout provides a more efficient way to access
 * internal members of the C++ class ProgramStore owned by librs. Unfortunately,
 * since this class has virtual members, we can't simply use offsetof() or any
 * other compiler trickery to dynamically get the appropriate values at
 * build-time. This layout may need to be updated whenever
 * frameworks/base/libs/rs/rsProgramStore.h is modified.
 *
 * Having the layout information available in this file allows us to
 * accelerate functionality like rsgProgramStoreGetDepthFunc(). Without this
 * information, we would not be able to inline the bitcode, thus resulting in
 * potential runtime performance penalties for tight loops operating on
 * program store.
 *
 *****************************************************************************/
typedef struct ProgramStore {
    char __pad[36];
    struct {
        struct {
            bool ditherEnable;
            bool colorRWriteEnable;
            bool colorGWriteEnable;
            bool colorBWriteEnable;
            bool colorAWriteEnable;
            rs_blend_src_func blendSrc;
            rs_blend_dst_func blendDst;
            bool depthWriteEnable;
            rs_depth_func depthFunc;
        } state;
    } mHal;
} ProgramStore_t;

/*****************************************************************************
 * CAUTION
 *
 * The following structure layout provides a more efficient way to access
 * internal members of the C++ class ProgramRaster owned by librs. Unfortunately,
 * since this class has virtual members, we can't simply use offsetof() or any
 * other compiler trickery to dynamically get the appropriate values at
 * build-time. This layout may need to be updated whenever
 * frameworks/base/libs/rs/rsProgramRaster.h is modified.
 *
 * Having the layout information available in this file allows us to
 * accelerate functionality like rsgProgramRasterGetCullMode(). Without this
 * information, we would not be able to inline the bitcode, thus resulting in
 * potential runtime performance penalties for tight loops operating on
 * program raster.
 *
 *****************************************************************************/
typedef struct ProgramRaster {
    char __pad[36];
    struct {
        struct {
            bool pointSprite;
            rs_cull_mode cull;
        } state;
    } mHal;
} ProgramRaster_t;

/*****************************************************************************
 * CAUTION
 *
 * The following structure layout provides a more efficient way to access
 * internal members of the C++ class Sampler owned by librs. Unfortunately,
 * since this class has virtual members, we can't simply use offsetof() or any
 * other compiler trickery to dynamically get the appropriate values at
 * build-time. This layout may need to be updated whenever
 * frameworks/base/libs/rs/rsSampler.h is modified.
 *
 * Having the layout information available in this file allows us to
 * accelerate functionality like rsgProgramRasterGetMagFilter(). Without this
 * information, we would not be able to inline the bitcode, thus resulting in
 * potential runtime performance penalties for tight loops operating on
 * samplers.
 *
 *****************************************************************************/
typedef struct Sampler {
    char __pad[28];

    struct {
        void *drv;
        struct {
            rs_sampler_value magFilter;
            rs_sampler_value minFilter;
            rs_sampler_value wrapS;
            rs_sampler_value wrapT;
            rs_sampler_value wrapR;
            float aniso;
        } state;
    } mHal;
} Sampler_t;

/*****************************************************************************
 * CAUTION
 *
 * The following structure layout provides a more efficient way to access
 * internal members of the C++ class Element owned by librs. Unfortunately,
 * since this class has virtual members, we can't simply use offsetof() or any
 * other compiler trickery to dynamically get the appropriate values at
 * build-time. This layout may need to be updated whenever
 * frameworks/base/libs/rs/rsElement.h is modified.
 *
 * Having the layout information available in this file allows us to
 * accelerate functionality like rsElementGetSubElementCount(). Without this
 * information, we would not be able to inline the bitcode, thus resulting in
 * potential runtime performance penalties for tight loops operating on
 * elements.
 *
 *****************************************************************************/
typedef struct Element {
    char __pad[28];
    struct {
        void *drv;
        struct {
            rs_data_type dataType;
            rs_data_kind dataKind;
            uint32_t vectorSize;
            uint32_t elementSizeBytes;

            // Subelements
            const void **fields;
            uint32_t *fieldArraySizes;
            const char **fieldNames;
            uint32_t *fieldNameLengths;
            uint32_t *fieldOffsetBytes;
            uint32_t fieldsCount;
        } state;
    } mHal;
} Element_t;

/*****************************************************************************
 * CAUTION
 *
 * The following structure layout provides a more efficient way to access
 * internal members of the C++ class Type owned by librs. Unfortunately,
 * since this class has virtual members, we can't simply use offsetof() or any
 * other compiler trickery to dynamically get the appropriate values at
 * build-time. This layout may need to be updated whenever
 * frameworks/base/libs/rs/rsType.h is modified.
 *
 * Having the layout information available in this file allows us to
 * accelerate functionality like rsAllocationGetElement(). Without this
 * information, we would not be able to inline the bitcode, thus resulting in
 * potential runtime performance penalties for tight loops operating on
 * types.
 *
 *****************************************************************************/
typedef struct Type {
    char __pad[28];
    struct {
        void *drv;
        struct {
            const void * element;
            uint32_t dimX;
            uint32_t dimY;
            uint32_t dimZ;
            uint32_t *lodDimX;
            uint32_t *lodDimY;
            uint32_t *lodDimZ;
            uint32_t *lodOffset;
            uint32_t lodCount;
            bool faces;
        } state;
    } mHal;
} Type_t;

/*****************************************************************************
 * CAUTION
 *
 * The following structure layout provides a more efficient way to access
 * internal members of the C++ class Mesh owned by librs. Unfortunately,
 * since this class has virtual members, we can't simply use offsetof() or any
 * other compiler trickery to dynamically get the appropriate values at
 * build-time. This layout may need to be updated whenever
 * frameworks/base/libs/rs/rsMesh.h is modified.
 *
 * Having the layout information available in this file allows us to
 * accelerate functionality like rsMeshGetVertexAllocationCount(). Without this
 * information, we would not be able to inline the bitcode, thus resulting in
 * potential runtime performance penalties for tight loops operating on
 * meshes.
 *
 *****************************************************************************/
typedef struct Mesh {
    char __pad[28];
    struct {
        void *drv;
        struct {
            void **vertexBuffers;
            uint32_t vertexBuffersCount;

            // indexBuffers[i] could be NULL, in which case only primitives[i] is used
            void **indexBuffers;
            uint32_t indexBuffersCount;
            rs_primitive *primitives;
            uint32_t primitivesCount;
        } state;
    } mHal;
} Mesh_t;
#endif // _RS_CORE_H_
