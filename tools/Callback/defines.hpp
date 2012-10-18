#ifndef _ZIA_API_DEFINES_H_
#define _ZIA_API_DEFINES_H_

#define _BOF_ZIA_API_           namespace zia { namespace api {
#define _EOF_ZIA_API_           } }

_BOF_ZIA_API_

enum {
    /*!
     * \brief Fatal ERROR.
     *
     * FATAL ERROR, stop the current flow.
     */
    ZIA_ERR = -1,

    /*!
     * \brief OK
     */
    ZIA_OK = 0,

    /*!
     * \brief Fail.
     *
     * The operation fail, but it is not fatal.
     * (deprecated)
     */
    ZIA_FAIL = 1,

    /*!
     * \brief Stop current operation.
     *
     * The operation succed or fail,
     * but stop the execution of this the operation.
     */
    ZIA_STOP = 2
};

_EOF_ZIA_API_

#endif /* _ZIA_API_DEFINES_H_ */
